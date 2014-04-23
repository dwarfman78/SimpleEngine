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
        //std::cout << "Particle Born" << std::endl;
        renderingContext.getParticleContext().getCurrentTime().restart();
        renderingContext.getParticleContext().setValid(true);
        renderingContext.getParticleContext().setAlive(true);
    };
    static void live(RenderingContext& renderingContext)
    {
        ParticleContext& pc = renderingContext.getParticleContext();

        //std::cout << "Particle : " <<  pc.isValid() <<" " << se::Utils::toString(pc.getLifeTime()) << " " << pc.getCurrentTime().getElapsedTime().asMicroseconds() << std::endl;
        if(pc.isValid() && pc.getCurrentTime().getElapsedTime().asMicroseconds() >= pc.getLifeTime())
        {
            pc.setAlive(false);
            renderingContext.unregister();
        }
    };
    static void die(RenderingContext& renderingContext) {};
};
}
#endif // ParticleStrategy_hpp
