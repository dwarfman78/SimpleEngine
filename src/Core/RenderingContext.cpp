#include <SimpleEngine/Core/RenderingContext.hpp>
namespace se
{
    DrawingContext& RenderingContext::getDrawingContext()
    {
        return myDrawingContext;
    }
    ParticleContext& RenderingContext::getParticleContext()
    {
        return myParticleContext;
    }
    GeometricalContext& RenderingContext::getGeometricalContext()
    {
        return myGeometricalContext;
    }
    AnimationContext& RenderingContext::getAnimationContext()
    {
        return myAnimationContext;
    }
    WriteContext& RenderingContext::getWriteContext()
    {
        return myWriteContext;
    }
    SoundContext& RenderingContext::getSoundContext()
    {
        return mySoundContext;
    }
    bool RenderingContext::isValid() const
    {
        return true;
    }
    void RenderingContext::setInterpolation(const float interpolation)
    {
        myInterpolation = interpolation;
    }
    float RenderingContext::getInterpolation() const
    {
        return myInterpolation;
    }
}
