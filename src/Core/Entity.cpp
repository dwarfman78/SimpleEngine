#include <SimpleEngine/Core/Entity.hpp>
namespace se
{
Entity::Entity() : live([](RenderingContext& context)
{
    ;
}), die([](RenderingContext& context)
{
    ;
}),
myRenderingPosition(0)
{
    ;
}
Entity::~Entity()
{
    ;
}
RenderingContext& Entity::getContext()
{
    return myContext;
}
bool Entity::unregister() const
{
    return myContext.isUnregistered();
}
void Entity::setRenderingPosition(unsigned int position)
{

    myRenderingPosition = position;
}
Entity& Entity::makeWritable(const std::string& text)
{
    getContext().getWriteContext().setFont("arial.ttf");
    getContext().getWriteContext().setText(text);

    return *this;
}
Entity& Entity::makeDrawable(const std::string& img)
{
    getContext().getDrawingContext().setSprite(Manager<sf::Texture,sf::Sprite,se::xmlTags::IMAGE>::getInstance()->getResource(img));

    return *this;
}
Entity& Entity::makeSound(const std::string& soundName)
{
    getContext().getSoundContext().setSound(soundName,Manager<sf::SoundBuffer,sf::Sound,se::xmlTags::SOUND>::getInstance()->getResource(soundName));

    return *this;
}
Entity& Entity::makeParticle(std::function<void(RenderingContext&)> born, std::function<void(RenderingContext&)> live, std::function<void(RenderingContext&)> die)
{

    born(getContext());

    this->live = live;
    this->die = die;

    return *this;
}
Entity& Entity::setColor(const sf::Color& color)
{
    getContext().getDrawingContext().getSprite().setColor(color);

    getContext().getWriteContext().getText().setColor(color);

    return *this;
}
Entity& Entity::makeAnimable(const std::string& animationName)
{
    const Animation& currentAnim = getContext().getAnimationContext().getAnimation();

    if(!Utils::equals(currentAnim.getName(),animationName))
    {
        se::Animation& animation = AnimationManager::getInstance()->getAnimation(animationName);

        getContext().getAnimationContext().setAnimation(animation);
    }

    return *this;
}
Entity& Entity::setPosition(float x, float y)
{
    getContext().getGeometricalContext().getPosition().x = x;
    getContext().getGeometricalContext().getPosition().y = y;

    return *this;
}
Entity& Entity::setScale(float x, float y)
{
    getContext().getGeometricalContext().getScale().x = x;
    getContext().getGeometricalContext().getScale().y = y;

    return *this;
}
const sf::Vector3f& Entity::getPosition()
{
    return getContext().getGeometricalContext().getPosition();
}
const sf::Sprite& Entity::getSprite()
{
    return getContext().getDrawingContext().getSprite();
}
const Animation& Entity::getAnimation()
{
    return getContext().getAnimationContext().getAnimation();
}
Entity& Entity::setRotation(float rotation)
{
    GeometricalContext& geometricalContext = getContext().getGeometricalContext();
    if(geometricalContext.isValid())
    {
        geometricalContext.setRotation(rotation);
    }
    return *this;
}
Entity& Entity::setOrigin(float x, float y)
{
    GeometricalContext& geometricalContext = getContext().getGeometricalContext();
    if(geometricalContext.isValid())
    {
        geometricalContext.setOrigin(x,y);
    }
    return *this;
}
void Entity::render()
{
    myAnimationStrategy.render(getContext());
    myDrawingStrategy.render(getContext());
    myWriteStrategy.render(getContext());

    // particles
    live(getContext());

    if(!getContext().getParticleContext().isAlive())
        die(getContext());

    mySoundStrategy.render(getContext());
}
void Entity::renderLogic()
{
    ;
}
unsigned int Entity::renderingPosition() const
{
    return myRenderingPosition;
}
void Entity::interpolate(const float interpolation)
{
    getContext().setInterpolation(interpolation);
}
}
