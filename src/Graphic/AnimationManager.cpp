#include <SimpleEngine/Graphic/AnimationManager.hpp>
namespace se
{
    AnimationManager::AnimationManager()
    {
        Logger log("AnimationManager::AnimationManager");

        log << "Trying to load animations config file : " + ANIMATIONS_CONF_FILE;

        pugi::xml_document doc;

        if(doc.load_file(ANIMATIONS_CONF_FILE.c_str()))
        {
            log << "Medias file successfully loaded, loading resources";

            // load resources from conf
            loadAnimations(doc);
        }
        else
        {
            log << "Error, couldnt open animations config file : " + ANIMATIONS_CONF_FILE;
        }
    }
    Animation& AnimationManager::getAnimation(const std::string& name)
    {
        std::map<std::string,Animation*>::iterator it = myAnimations.find(name);

        if(it != myAnimations.end())
        {
            return *(it->second);
        }
        else
        {
            return defaultAnimation;
        }
    }
    void AnimationManager::loadAnimations(const pugi::xml_document& doc)
    {
        Logger log("Manager::loadAnimations");

        pugi::xml_node config = doc.child("animations");

        log << "parsing animations : ";

        for (pugi::xml_node animation = config.child("animation"); animation; animation = animation.next_sibling("animation"))
        {// foreach <animation ..

            std::vector<sf::FloatRect> frameSet; //prepare the frame set
            std::string animationName = animation.attribute("name").value(); // retrieve animation's name
            sf::Uint32 duration = animation.attribute("duration").as_int();

            // do some logging
            log << "\t found : " + animationName;

            log << "\t parsing frames : ";

            for (pugi::xml_node frame = animation.child("frame"); frame; frame = frame.next_sibling("frame"))
            {// foreach <frame ..

                sf::FloatRect currentFrame;

                currentFrame.left = frame.attribute("left").as_float();
                currentFrame.top = frame.attribute("top").as_float();
                currentFrame.height = frame.attribute("height").as_float();
                currentFrame.width = frame.attribute("width").as_float();

                frameSet.push_back(currentFrame);

                log << "\t\t found : " << currentFrame.left << currentFrame.top << currentFrame.height << currentFrame.width;
            }

            Animation* myAnimation = new Animation(animationName,frameSet,duration);

            myAnimations[animationName] = myAnimation;
        }
    }
}
