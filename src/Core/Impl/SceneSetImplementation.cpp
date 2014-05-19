#include <SimpleEngine/Core/Impl/SceneSetImplementation.hpp>
namespace se
{
SceneSetImplementation::SceneSetImplementation() :
    myRenderables([](std::shared_ptr<Renderable> rOne, std::shared_ptr<Renderable> rTwo)->bool { return rOne->renderingPosition() <= rTwo->renderingPosition();}),
              myPhysicWorld(b2Vec2(0.0,PhysicBodyManager::getInstance()->getGravity()))
{
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(Utils::pixelsToMeters(0.0f), Utils::pixelsToMeters(0.0f));
    b2Body* groundBody = myPhysicWorld.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(Utils::pixelsToMeters(800.0f),Utils::pixelsToMeters(600.0f));
    groundBody->CreateFixture(&groundBox, 1.0f);

    myGround = groundBody;

}
SceneSetImplementation::~SceneSetImplementation()
{
    for(std::set<std::shared_ptr<Renderable> >::iterator i = myRenderables.begin(); i!=myRenderables.end();)
    {
        myRenderables.erase(i++);
    }
}
void SceneSetImplementation::registerRenderable(std::shared_ptr<Renderable> renderable)
{
    // Add a reference to a renderable
    myRenderables.insert(renderable);
}
void SceneSetImplementation::unregisterRenderable(std::shared_ptr<Renderable> renderable)
{
    myRenderables.erase(renderable);
}
void SceneSetImplementation::render()
{
    for(auto& i : myRenderables)
    {
        // Render it
        if(!(i)->unregister())
            (i)->render();
    }
}
void SceneSetImplementation::cleanRenderables()
{
    for(std::set<std::shared_ptr<Renderable> >::iterator i = myRenderables.begin(); i!=myRenderables.end();)
    {
        if((*i)->unregister())
        {
            myRenderables.erase(i++);
        }
        else
        {
            ++i;
        }
    }

}
void SceneSetImplementation::renderLogic()
{
    for(auto& i : myRenderables)
    {
        if(!(i)->unregister())
            (i)->renderLogic();
    }
}
void SceneSetImplementation::interpolate(const float interpolation)
{
    for(auto& i : myRenderables)
    {
        if(!(i)->unregister())
            (i)->interpolate(interpolation);
    }
}
bool SceneSetImplementation::unregister() const
{
    return false;
}
unsigned int SceneSetImplementation::renderingPosition() const
{
    return 0;
}
std::shared_ptr<Entity> SceneSetImplementation::addTemporaryPhysicParticle(float positionX, float positionY, float originX, float originY, float rotation, sf::Int64 duration, const std::string& media, const std::string& body)
{
    std::shared_ptr<Entity> entity = std::make_shared<Entity>();

    entity->makeDrawable(media);

    entity->makeParticle(
        [](RenderingContext& context)
    {
        ParticleStrategy::born(context);
    },
    [](RenderingContext& context)
    {
        ParticleStrategy::live(context);
    },
    [](RenderingContext& context)
    {
        ParticleStrategy::die(context);
    }
    );
    entity->setPosition(positionX,positionY);

    entity->makePhysic(body,myPhysicWorld);

    entity->getContext().getParticleContext().setLifeTime(duration);

    entity->setOrigin(originX,originY);

    entity->setRotation(rotation);

    registerRenderable(entity);

    return entity;
}
std::shared_ptr<Entity>  SceneSetImplementation::addTemporaryParticleEntity(float positionX, float positionY, float originX, float originY, float rotation, sf::Int64 duration, const std::string& media, const std::string& animation)
{
    std::shared_ptr<Entity> entity = std::make_shared<Entity>();

    entity->makeDrawable(media);

    entity->makeAnimable(animation);

    entity->makeParticle(
        [](RenderingContext& context)
    {
        ParticleStrategy::born(context);
    },
    [](RenderingContext& context)
    {
        ParticleStrategy::live(context);
    },
    [](RenderingContext& context)
    {
        ParticleStrategy::die(context);
    }
    );
    entity->setPosition(positionX,positionY);

    entity->getContext().getParticleContext().setLifeTime(duration);

    entity->setOrigin(originX,originY);

    entity->setRotation(rotation);

    registerRenderable(entity);

    return entity;
}

std::shared_ptr<Entity>  SceneSetImplementation::addTemporarySoundEntity(const std::string& soundName)
{
    std::shared_ptr<Entity> entity = std::make_shared<Entity>();

    entity->makeSound(soundName);
    entity->getContext().getParticleContext().setLifeTime(entity->getContext().getSoundContext().getSound().getBuffer()->getDuration().asMicroseconds());
    entity->makeParticle(
        [](RenderingContext& context)
    {
        ParticleStrategy::born(context);
    },
    [](RenderingContext& context)
    {
        ParticleStrategy::live(context);
    },
    [](RenderingContext& context)
    {
        ParticleStrategy::die(context);
    }
    );

    registerRenderable(entity);

    return entity;
}
void SceneSetImplementation::loadMusic(const std::string& fileName)
{
    myMusic.openFromFile(fileName);
    myMusic.setLoop(true);
    myMusic.setVolume(30);
}
const sf::Music& SceneSetImplementation::getCurrentMusic() const
{
    return myMusic;
}
void SceneSetImplementation::playMusic()
{
    myMusic.play();
}
void SceneSetImplementation::pauseMusic()
{
    //myMusic.pause();
    // Temporary hack
    myMusic.stop();
}

}
