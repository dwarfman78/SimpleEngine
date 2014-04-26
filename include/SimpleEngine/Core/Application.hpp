#ifndef Application_h
#define Application_h

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/Singleton.hpp>
#include <SimpleEngine/ToolBox/Logger.hpp>
#include <SimpleEngine/Graphic/GraphicEngine.hpp>
#include <SimpleEngine/Core/Renderable.hpp>
#include <SimpleEngine/Core/Observer.hpp>
#include <SimpleEngine/Core/Event.hpp>
#include <SimpleEngine/Core/Entity.hpp>
#include <SimpleEngine/Graphic/ParticleStrategy.hpp>
#include <SimpleEngine/Core/Impl/SceneSetImplementation.hpp>
#include <SimpleEngine/Core/Scene.hpp>
////////////////////////////////////////////////////////////

namespace se
{
////////////////////////////////////////////////////////////
/// Class Application.
/// Constructs main window and dispatch events incoming from it.
/// Manage main loop and Renderable.
////////////////////////////////////////////////////////////
class SE_API Application : public Singleton<Application>
{
    friend class Singleton<Application>;

private:

    ////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////
    Application();

public:

    ////////////////////////////////////////////////////////////
    /// Start the application (launch rendering window, start handling events...)
    /// It is your entry point to the framework.
    ////////////////////////////////////////////////////////////
    void start();

    ////////////////////////////////////////////////////////////
    /// Stop the application which obviously close the rendering window
    ////////////////////////////////////////////////////////////
    void stop();

    ////////////////////////////////////////////////////////////
    /// Pause application (no call to render or renderlogic)
    ////////////////////////////////////////////////////////////
    void pause();

    void reset();

    ////////////////////////////////////////////////////////////
    /// Unpause application
    ////////////////////////////////////////////////////////////
    void unpause();

    bool isPaused() const;

    ////////////////////////////////////////////////////////////
    /// Add renderable to the application, its "render" method will be called
    /// at each rendering loop
    /// \param renderable: a reference to a renderable, you have to handle memory allocation.
    ////////////////////////////////////////////////////////////
    //void registerRenderable(std::shared_ptr<Renderable> renderable);

    ////////////////////////////////////////////////////////////
    /// Remove a renderable from the application.
    /// A renderable must be removed before it is freed from the memory.
    /// Nothing happend if the reference is not valid or the renderable is not registered.
    /// \param renderable : a reference to a registered renderable.
    ////////////////////////////////////////////////////////////
    //void unregisterRenderable(std::shared_ptr<Renderable> renderable);

    ////////////////////////////////////////////////////////////
    /// Add an observer to the application. Observers are notified (notify method is called)
    /// when any event occurs. It could be an SFML wrapped event (like keypressed) or a SE event (from gui)
    /// \param observer : a reference to an observer.
    ////////////////////////////////////////////////////////////
    void registerObserver(std::shared_ptr<Observer> observer);

    ////////////////////////////////////////////////////////////
    /// Remove an observer from the application
    ////////////////////////////////////////////////////////////
    void unregisterObserver(std::shared_ptr<Observer> observer);

    void addTemporaryParticleEntity(float positionX, float positionY, float originX, float originY, float rotation, sf::Int64 duration, const std::string& media, const std::string& animation);

    void addTemporarySoundEntity(const std::string& soundName);
    ////////////////////////////////////////////////////////////
    /// Return current frame time
    ////////////////////////////////////////////////////////////
    sf::Int64 getFrameTime() const;

    void loadMusic(const std::string& fileName);

    void playMusic();

    void pauseMusic();

    const sf::Music& getCurrentMusic() const;

    void setBackground(const std::string& name);

    ////////////////////////////////////////////////////////////
    /// Push a scene to the scene stack. The last scene pushed will be the scene rendered.
    ////////////////////////////////////////////////////////////
    void pushScene(std::shared_ptr<Scene> scene);

    ////////////////////////////////////////////////////////////
    /// Pop a scene from the scene stack.
    ////////////////////////////////////////////////////////////
    void popScene();

    ////////////////////////////////////////////////////////////
    /// Get current scene to be rendered.
    ////////////////////////////////////////////////////////////
    std::shared_ptr<Scene> getCurrentScene() const;

private:

    ////////////////////////////////////////////////////////////
    /// Init stuff ...
    ////////////////////////////////////////////////////////////
    void initGraphicEngine(const pugi::xml_document& doc);
    void loadVideoMode(const pugi::xml_document& doc, sf::VideoMode& vm) const;
    void logAvailableVideoModes(Logger& log) const;
    ////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////
    /// Main loop methods
    ////////////////////////////////////////////////////////////
    void handleEvents();
    void render();
    void renderLogic();
    void interpolate(const float interpolation);
    void notifyObservers(const sf::Event& event) const;
    void cleanParticles();
    void cleanRenderables();
    ////////////////////////////////////////////////////////////

    std::stack<std::shared_ptr<Scene> > mySceneStack;

    ////////////////////////////////////////////////////////////
    /// Renderables and observers data storage
    ////////////////////////////////////////////////////////////
    std::set< std::shared_ptr<Observer> > myObservers;
    std::set< std::shared_ptr<Entity> > myParticles;
    ////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////
    /// Data for main loop management
    ////////////////////////////////////////////////////////////
    sf::Clock myClock;
    int myMaxFps;
    sf::Int64 myNextTick;
    ////////////////////////////////////////////////////////////

    /** Paused application yes/no **/
    bool paused;

    sf::Music myMusic;

    bool myBackgroundIsSet;
    sf::Texture myBackgroundTexture;
    sf::Sprite myBackgroundSprite;


};
}
#endif
