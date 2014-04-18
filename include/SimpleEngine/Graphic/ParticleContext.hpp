#ifndef ParticleContext_hpp
#define ParticleContext_hpp
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/ToolBox/NonCopyable.hpp>
#include <SimpleEngine/Core/Context.hpp>
////////////////////////////////////////////////////////////
namespace se
{
    ////////////////////////////////////////////////////////////
    /// Particle context, this class contains information about the entity as a particle.
    ////////////////////////////////////////////////////////////
    class SE_API ParticleContext : public NonCopyable, public Context
    {
    public:
        ParticleContext();
        ParticleContext(sf::Int64 lifeTime);
        bool isAlive() const;
        void setAlive(bool alive);
        void setValid(bool valid);
        sf::Clock& getCurrentTime();
        sf::Int64 getLifeTime();
        void setLifeTime(sf::Int64 lifeTime);
        bool isValid() const;

    private:
        bool alive;
        bool valid;
        sf::Clock myCurrentTime;
        sf::Int64 myLifeTime;
    };
}
#endif // ParticleContext_hpp
