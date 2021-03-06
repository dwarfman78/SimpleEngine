#include <SimpleEngine/Core/RenderingContext.hpp>
namespace se
{
    RenderingContext::RenderingContext() : unregistered(false){}
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
    PhysicContext& RenderingContext::getPhysicContext()
    {
        return myPhysicContext;
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
    void RenderingContext::unregister()
    {
        unregistered = true;
    }
    bool RenderingContext::isUnregistered() const
    {
        return unregistered;
    }
}
