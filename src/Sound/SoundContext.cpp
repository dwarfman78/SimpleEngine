#include <SimpleEngine/Sound/SoundContext.hpp>
namespace se
{
/** @brief SoundContext
  *
  * @todo: document this function
  */
SoundContext::SoundContext() : myValid(false)
{

}

/** @brief SoundContext
  *
  * @todo: document this function
  */
SoundContext::SoundContext(const std::string& soundName) :
    mySound(Manager<sf::SoundBuffer,sf::Sound,se::xmlTags::SOUND>::getInstance()->getResource(soundName)),
    myPlayOnce(true),
    myPlayed(false),
    myValid(true),
    myCurrentSoundName(soundName.c_str())
{

}
void SoundContext::setSound(const std::string& soundName, sf::Sound sound)
{
    if(soundName.compare(myCurrentSoundName) != 0)
    {
        mySound = sound;
        myValid = true;
        myPlayOnce = true;
        myPlayed = false;
        myCurrentSoundName = soundName;
    }

}
const std::string& SoundContext::getCurrentSoundName() const{
return myCurrentSoundName;
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
sf::Sound& SoundContext::getSound()
{
    return mySound;
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
