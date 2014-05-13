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
            context.getSound().setVolume(50);
            context.getSound().play();
            context.setPlayed(true);
        }
    }
}

}
