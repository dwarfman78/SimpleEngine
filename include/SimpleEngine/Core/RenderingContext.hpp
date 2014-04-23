#ifndef RenderingContext_hpp
#define RenderingContext_hpp

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/NonCopyable.hpp>
#include <SimpleEngine/Graphic/GeometricalContext.hpp>
#include <SimpleEngine/Graphic/DrawingContext.hpp>
#include <SimpleEngine/Graphic/AnimationContext.hpp>
#include <SimpleEngine/Graphic/WriteContext.hpp>
#include <SimpleEngine/Graphic/ParticleContext.hpp>
#include <SimpleEngine/Sound/SoundContext.hpp>
#include <SimpleEngine/Core/Context.hpp>
////////////////////////////////////////////////////////////
namespace se
{
    ////////////////////////////////////////////////////////////
    /// Global entity's context
    ////////////////////////////////////////////////////////////
    class SE_API RenderingContext : public NonCopyable, public Context
    {
        public:
        RenderingContext();
        DrawingContext& getDrawingContext();
        GeometricalContext& getGeometricalContext();
        AnimationContext& getAnimationContext();
        WriteContext& getWriteContext();
        ParticleContext& getParticleContext();
        SoundContext& getSoundContext();
        bool isValid() const;
        void setInterpolation(const float interpolation);
        float getInterpolation() const;
        void unregister();
        bool isUnregistered() const;
        private:
        DrawingContext myDrawingContext;
        GeometricalContext myGeometricalContext;
        AnimationContext myAnimationContext;
        WriteContext myWriteContext;
        ParticleContext myParticleContext;
        SoundContext mySoundContext;
        float myInterpolation;
        bool unregistered;
    };
}
#endif
