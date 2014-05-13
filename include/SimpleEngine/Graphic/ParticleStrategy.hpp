#ifndef ParticleStrategy_hpp
#define ParticleStrategy_hpp
#include <SimpleEngine/Core/RenderingContext.hpp>
namespace se
{
class SE_API ParticleStrategy
{
public:

    static void born(RenderingContext& renderingContext)
    {
        ParticleContext& pc = renderingContext.getParticleContext();

        pc.getCurrentTime().restart();
        pc.setValid(true);
        pc.setAlive(true);
    };
    static void live(RenderingContext& renderingContext)
    {
        ParticleContext& pc = renderingContext.getParticleContext();

        if(pc.isValid() && pc.getCurrentTime().getElapsedTime().asMicroseconds() >= pc.getLifeTime())
        {
            pc.setAlive(false);
        }
    };
    static void die(RenderingContext& renderingContext) {renderingContext.unregister();};
};
}
#endif // ParticleStrategy_hpp
