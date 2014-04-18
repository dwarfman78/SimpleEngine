#include <SimpleEngine/Graphic/Animation.hpp>
namespace se
{
    Animation::Animation():
    myName("default")
    {
        ;
    }
    Animation::Animation(const std::string name, const std::vector<sf::FloatRect> frames, sf::Uint32 duration = 0) :
    myName(name),
    myFrames(frames),
    myDuration(duration)
    {
        ;
    }
    const std::vector<sf::FloatRect>& Animation::getFrames() const
    {
        return myFrames;
    }
    sf::Uint32 Animation::getDuration() const
    {
        return myDuration;
    }
    const std::string& Animation::getName() const
    {
        return myName;
    }
}
