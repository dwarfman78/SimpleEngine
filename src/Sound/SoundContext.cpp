#include <SimpleEngine/Sound/SoundContext.hpp>
namespace se
{
/** @brief SoundContext
  *
  * @todo: document this function
  */
SoundContext::SoundContext() : myValid(false), mySound(nullptr)
{

}

/** @brief SoundContext
  *
  * @todo: document this function
  */
SoundContext::SoundContext(const std::string& soundName) :
    myPlayOnce(true),
    myPlayed(false),
    myValid(true),
    myCurrentSoundName(soundName.c_str()),
    mySound(SoundPool::getInstance()->getSound(soundName))
{

}
void SoundContext::setSound(const std::string& soundName)
{
    if(soundName.compare(myCurrentSoundName) != 0)
    {
        myValid = true;
        myPlayOnce = true;
        myPlayed = false;
        myCurrentSoundName = soundName;
        mySound = SoundPool::getInstance()->getSound(soundName);
    }

}
const std::string& SoundContext::getCurrentSoundName() const{
return myCurrentSoundName;
}
std::shared_ptr<sf::Sound> SoundContext::getSound()
{
    return mySound;
}

/** @brief isValid
  *
  * @todo: document this function
  */
bool SoundContext::isValid() const
{
    return myValid;
}
/** @brief setPlayOnce
  *
  * @todo: document this function
  */
void SoundContext::setPlayOnce(bool playOnce)
{
    myPlayOnce = playOnce;
}

/** @brief played
  *
  * @todo: document this function
  */
bool SoundContext::played() const
{
    return myPlayed;
}
/** @brief reset
  *
  * @todo: document this function
  */
void SoundContext::reset()
{
    myPlayed = false;
}
bool SoundContext::playOnce() const
{
    return myPlayOnce;
}
void SoundContext::setPlayed(bool played)
{
    myPlayed = played;
}

}
