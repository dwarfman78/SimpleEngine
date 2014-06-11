#include <SimpleEngine/Sound/SoundPool.hpp>
namespace se
{
std::shared_ptr<sf::Sound> SoundPool::getSound(const std::string& soundName)
{
    std::shared_ptr<sf::Sound> returnValue = nullptr;
    try
    {
        auto stacque = mySounds.at(soundName);
        if(!stacque.empty())
        {
            returnValue = stacque.top();
            stacque.pop();
        }

    }
    catch (const std::out_of_range& oor)
    {
        std::stack<std::shared_ptr<sf::Sound> > staque;
        auto manager = Manager<sf::SoundBuffer,sf::Sound,se::xmlTags::SOUND>::getInstance();

        for(unsigned int i = 0;i<MAX_SF_SOUND/manager->getNbLoadedResources(); i++)
        {
            staque.push(std::make_shared<sf::Sound>(manager->getResource(soundName)));
        }
        mySounds[soundName] = staque;

        returnValue = getSound(soundName);
    }
    return returnValue;
}
void SoundPool::releaseSound(const std::string& soundName, std::shared_ptr<sf::Sound> sound)
{
    try
    {
        auto stacque = mySounds.at(soundName);
        stacque.push(sound);
    }
    catch (const std::out_of_range& oor)
    {
    }
}
}
