#include <SimpleEngine/Graphic/AnimationStrategy.hpp>
namespace se
{
    void AnimationStrategy::render(RenderingContext& rc)
    {
        Logger log("AnimationStrategy::render::"+se::Utils::toString(this));

        // Getting animation context from global context
        AnimationContext& context = rc.getAnimationContext();

        if(context.isValid())
        {
            log << "Context valid, proceeding with animation";

            // Add time between two calls to current time.
            context.addToCurrentTime(context.getClock().restart().asMicroseconds());

            // Get the diff between current time and frame display time.
            int diff = context.getFrameTime() - context.getCurrentTime();

            if(diff<=0)
            {
                // It is time to switch to the next frame of the animation.
                log << "Switching to next animation frame with prediction of : " + se::Utils::toString(diff);

                // We may be too late regarding frame display time, so we have to catch up.
                context.setCurrentTime(diff*-1);

                // Actual switching.
                context.getFrameIterator()++;

                // Reset the animation if we get to the end.
                if(context.getFrameIterator() == context.getAnimation().getFrames().end())
                {
                    context.initAnimation();
                }
            }
        }
    }
}
