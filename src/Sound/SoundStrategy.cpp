#include <SimpleEngine/Sound/SoundStrategy.hpp>
namespace se
{
/** @brief render
  *
  * @todo: document this function
  */
void SoundStrategy::render(RenderingContext& rc)
{
    SoundContext& context = rc.getSoundContext();

    if(context.isValid())
    {
        if(!context.playOnce()||(context.playOnce()&&!context.played()))
        {
            auto sound = context.getSound();
            if(sound!=nullptr)
            {
                sound->setVolume(50);
                sound->play();
                context.setPlayed(true);
            }

        }
    }
}

}
