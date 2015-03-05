#include <SimpleEngine/Core/Application.hpp>

namespace se
{
    Application::Application() : paused(false), myBackgroundIsSet(false)
    {
        Logger log("Application::Application");

        log << "Trying to load application config file : " + APPLICATION_CONF_FILE;

        pugi::xml_document doc;

        if (doc.load_file(APPLICATION_CONF_FILE.c_str()))
        {
            log << "Config file successfully loaded, initializing engines";

            // init graphic engine from conf
            initGraphicEngine(doc);
        }
        else
        {
            log << "Error, couldnt open application config file : " + APPLICATION_CONF_FILE;
        }

        pushScene(std::make_shared<SceneSetImplementation>());
    }

    void Application::initGraphicEngine(const pugi::xml_document &doc)
    {
        Logger log("Application::initGraphicEngine");

        pugi::xml_node screen = doc.child("application").child("screen");

        std::string isConsole = screen.attribute("console").value();

        if (isConsole.compare("true") == 0)
        {
            log << "console application";
            myConsoleApplication = true;
        }
        else
        {
            myConsoleApplication = false;
        }
        if(!myConsoleApplication)
        {
            //load video mode from xml file into vm
            sf::VideoMode vm;

            loadVideoMode(doc, vm);

            if (vm.isValid())
            {
                // we check whether or not the videomode is valid

                log << "Video mode successfully created, creating application window";

                sf::RenderWindow &window = GraphicEngine::getInstance()->getRenderWindow();

                // create the render window with title and decoration
                window.create(vm, screen.attribute("title").value(), screen.attribute("decoration").as_int());

                myMaxFps = screen.attribute("maxfps").as_int();
                window.setFramerateLimit(myMaxFps * 4);

                GraphicEngine::getInstance()->init();

            }
            else
            {
                // Video mode is invalid, we log available video mode

                log << "Video mode invalid cannot create application window";

                // Log avalaible modes
                logAvailableVideoModes(log);
            }

            GraphicEngine::getInstance()->setShowFps(screen.attribute("showfps").as_bool());
        }
    }

    bool Application::isPaused() const
    {
        return paused;
    }


    void Application::start()
    {
        Logger log("Application::start");

        log << "Starting application";

        sf::RenderWindow &window = GraphicEngine::getInstance()->getRenderWindow();

        myNextTick = myClock.getElapsedTime().asMicroseconds();
        unsigned int loops = 0;
        sf::Int64 windowSize = 1000000 / myMaxFps;

        if (mySceneStack.empty())
            mySceneStack.push(std::make_shared<SceneSetImplementation>());

        while (window.isOpen()||myConsoleApplication)
        {
            loops = 0;

            // Handle window's events
            handleEvents();
            while (myClock.getElapsedTime().asMicroseconds() >= myNextTick && loops < 5)
            {

                if (!paused)
                {
                    renderLogic();

                    myNextTick += windowSize;

                }

                loops++;

                //cleanParticles();
                cleanRenderables();
            }

            //Interpolate frames
            interpolate((float) (myClock.getElapsedTime().asMicroseconds() + windowSize - myNextTick) / windowSize);

            window.clear(sf::Color(96, 96, 96));

            if (myBackgroundIsSet)
            {
                se::GraphicEngine::getInstance()->draw(myBackgroundSprite);
            }


            // Render all renderables
            getCurrentScene()->getPhysicWorld().Step(1 / 60.f, 8, 3);
            render();

            sf::RenderTexture &renderTexture = GraphicEngine::getInstance()->getRenderTexture();
            renderTexture.display();

            sf::Sprite finalSprite(renderTexture.getTexture());

            window.draw(finalSprite);
            // Display the window
            window.display();
        }

    }

    void Application::cleanRenderables()
    {
        if (!mySceneStack.empty())
            getCurrentScene()->cleanRenderables();
    }

    void Application::handleEvents()
    {
        sf::RenderWindow &window = GraphicEngine::getInstance()->getRenderWindow();

        sf::Event event;

        while (window.pollEvent(event))
        {
            // Notify observers
            notifyObservers(event);
        }
    }

    void Application::pushScene(std::shared_ptr<Scene> scene)
    {
        mySceneStack.push(scene);
    }

    void Application::popScene()
    {
        mySceneStack.pop();
    }

    std::shared_ptr<Scene> Application::getCurrentScene() const
    {
        return mySceneStack.top();
    }

    void Application::notifyObservers(const sf::Event &event) const
    {
        // Wrap sf::Event into se::Event
        Event localEvent(event);

        // Sweep observers
        for (std::set<std::shared_ptr<Observer> >::const_iterator i = myObservers.begin(); i != myObservers.end(); ++i)
        {
            // Notify them
            (*i)->notify(localEvent);
        }
    }

    void Application::stop()
    {
        GraphicEngine::getInstance()->getRenderWindow().close();
        myConsoleApplication=false;
    }

    void Application::interpolate(const float interpolation)
    {
        if (!mySceneStack.empty())
            mySceneStack.top()->interpolate(interpolation);
    }

    void Application::render()
    {
        // We render the current scene.
        if (!mySceneStack.empty())
            mySceneStack.top()->render();
    }

    void Application::renderLogic()
    {
        // We render the current scene.
        if (!mySceneStack.empty())
            mySceneStack.top()->renderLogic();
    }

    void Application::setBackground(const std::string &name)
    {
        if (myBackgroundTexture.loadFromFile(name))
        {
            myBackgroundIsSet = true;
            myBackgroundTexture.setRepeated(true);
            myBackgroundSprite.setTexture(myBackgroundTexture);
            myBackgroundSprite.setPosition(sf::Vector2f(0.f, 0.f));
            sf::RenderWindow &window = GraphicEngine::getInstance()->getRenderWindow();

            myBackgroundSprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
        }
    }

    void Application::reset()
    {
        while (!mySceneStack.empty())
            mySceneStack.pop();

        mySceneStack.push(std::make_shared<SceneSetImplementation>());
    }

    void Application::pause()
    {
        paused = true;
    }

    void Application::unpause()
    {
        paused = false;
        myClock.restart();
        myNextTick = 0;
    }

    void Application::registerObserver(std::shared_ptr<Observer> observer)
    {
        // Add a reference to a observer
        if (observer)
            myObservers.insert(observer);
    }

    void Application::unregisterObserver(std::shared_ptr<Observer> observer)
    {
        if (observer)
        {
            std::set<std::shared_ptr<Observer> >::const_iterator it = myObservers.find(observer);

            // remove a reference to a observer
            if (it != myObservers.end())
                myObservers.erase(it);
        }
    }

    void Application::loadVideoMode(const pugi::xml_document &doc, sf::VideoMode &vm) const
    {
        Logger log("Application::loadVideoMode");

        // Load video mode from xml
        pugi::xml_node screen = doc.child("application").child("screen");

        // Create video mode
        vm = sf::VideoMode(screen.attribute("width").as_int(), screen.attribute("height").as_int(), screen.attribute("depth").as_int());

        std::stringstream ss;

        // Log chosen video mode
        ss << vm.width << "x" << vm.height << "x" << vm.bitsPerPixel << "bpp";

        log << ss.str();

    }

    void Application::logAvailableVideoModes(Logger &log) const
    {
        // Log all valid video mode
        std::stringstream ss;

        log << "Available modes are : ";

        std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();

        for (std::size_t i = 0; i < modes.size(); ++i)
        {
            sf::VideoMode mode = modes[i];

            ss << "Mode #" << i << ": " << mode.width << "x" << mode.height << " - " << mode.bitsPerPixel << " bpp ";
        }

        log << ss.str();
    }

    sf::Int64 Application::getFrameTime() const
    {
        return myClock.getElapsedTime().asMicroseconds();
    }
}
