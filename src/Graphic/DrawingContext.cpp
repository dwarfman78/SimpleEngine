#include <SimpleEngine/Graphic/DrawingContext.hpp>
namespace se
{
    DrawingContext::DrawingContext()
    {
        ;
    }
    DrawingContext::DrawingContext(const std::string& img) :
    mySprite(Manager<sf::Texture,sf::Sprite,se::xmlTags::IMAGE>::getInstance()->getResource(img))
    {
        ;
    }
    sf::Sprite& DrawingContext::getSprite()
    {
        return mySprite;
    }
    DrawingContext& DrawingContext::setSprite(sf::Sprite sprite)
    {
        mySprite = sprite;

        return *this;
    }
    bool DrawingContext::isValid() const
    {
        return true;
    }
}
