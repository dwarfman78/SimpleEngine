#include <SimpleEngine/Graphic/AnimationContext.hpp>
namespace se
{
    AnimationContext::AnimationContext() :
    myAnimation(&AnimationManager::getInstance()->getAnimation("NULL")),
    valid(false)
    {
        ;
    }
    AnimationContext::AnimationContext(const std::string& animationName) :
    myAnimation(&AnimationManager::getInstance()->getAnimation(animationName))
    {
        initAnimation();
    }
    const Animation& AnimationContext::getAnimation() const
    {
        return *myAnimation;
    }
    sf::Int32 AnimationContext::getFrameTime() const
    {
        return myFrameTime;
    }
    sf::Clock& AnimationContext::getClock()
    {
        return myClock;
    }
    const sf::FloatRect& AnimationContext::getFrame() const
    {
        return *(myFrame);
    }
    AnimationContext& AnimationContext::setAnimation(const Animation& animation)
    {
        myAnimation = &animation;
        initAnimation();

        return *this;
    }
    void AnimationContext::initAnimation()
    {
        if(myAnimation->getFrames().size() != 0)
        {
            valid=true;
            myFrame = myAnimation->getFrames().begin();
            myClock.restart();
            myCurrentTime = 0;
            myFrameTime = myAnimation->getDuration() / myAnimation->getFrames().size();
        }
        else
        {
            valid=false;
            myFrame = myAnimation->getFrames().end();
        }
    }
    std::vector<sf::FloatRect>::const_iterator& AnimationContext::getFrameIterator()
    {
        return myFrame;
    }
    bool AnimationContext::isValid() const
    {
        return valid;
    }
    sf::Int32 AnimationContext::getCurrentTime() const
    {
        return myCurrentTime;
    }
    void AnimationContext::addToCurrentTime(sf::Int32 delta)
    {
        myCurrentTime+=delta;
    }
    void AnimationContext::setCurrentTime(sf::Int32 currentTime)
    {
        myCurrentTime = currentTime;
    }
}
