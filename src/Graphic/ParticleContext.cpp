#include <SimpleEngine/Graphic/ParticleContext.hpp>
namespace se
{

ParticleContext::ParticleContext() : valid(false)
{

}

ParticleContext::ParticleContext(sf::Int64 lifeTime) : valid(true),myLifeTime(lifeTime)
{

}

bool ParticleContext::isAlive() const
{
    return alive;
}

void ParticleContext::setAlive(bool alive)
{
    this->alive = alive;
}

sf::Clock& ParticleContext::getCurrentTime()
{
    return myCurrentTime;
}

sf::Int64 ParticleContext::getLifeTime()
{
    return myLifeTime;
}
void ParticleContext::setLifeTime(sf::Int64 lifeTime)
{
    myLifeTime = lifeTime;
}
bool ParticleContext::isValid() const
{
    return valid;
}
void ParticleContext::setValid(bool valid)
{
    this->valid = valid;
}
}
