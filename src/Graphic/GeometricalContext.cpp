#include <SimpleEngine/Graphic/GeometricalContext.hpp>
namespace se
{
    GeometricalContext::GeometricalContext():myScale(sf::Vector2f(1,1)),valid(false)
    {
        ;
    }

    GeometricalContext::GeometricalContext(const sf::Vector3f& pos, const float rotation) :
    myPosition(pos),
    myRotation(rotation),
    myScale(sf::Vector2f(1,1)),
    valid(true)
    {
        ;
    }

    GeometricalContext& GeometricalContext::setRotation(const float rotation)
    {
        myRotation = rotation;
        return *this;
    }
    sf::Vector2f& GeometricalContext::getScale()
    {
        return myScale;
    }

    float GeometricalContext::getRotation()
    {
        return myRotation;
    }

    GeometricalContext& GeometricalContext::setPosition(const sf::Vector3f& pos)
    {
        myPosition = pos;
        return *this;
    }

    sf::Vector3f& GeometricalContext::getPosition()
    {
        return myPosition;
    }

    bool GeometricalContext::isValid() const
    {
        return true;
    }

    sf::Vector2f& GeometricalContext::getOrigin()
    {
        return origin;
    }

    GeometricalContext& GeometricalContext::setOrigin(float x, float y)
    {
        origin.x = x;
        origin.y = y;

        return *this;
    }

}
