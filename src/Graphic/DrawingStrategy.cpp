#include <SimpleEngine/Graphic/DrawingStrategy.hpp>
namespace se
{
void DrawingStrategy::render(RenderingContext& rc)
{
    // Get contexts from global context.
    AnimationContext& animationContext = rc.getAnimationContext();
    DrawingContext& drawingContext = rc.getDrawingContext();
    GeometricalContext& geometricalContext = rc.getGeometricalContext();

    if(geometricalContext.isValid()&&drawingContext.isValid())
    {// if basic needed contexts are initialized

        // Get sprite from drawing context.
        sf::Sprite& s = drawingContext.getSprite();

        sf::Vector3f pos = geometricalContext.getPosition();

        // Set position and scale from geometric context.
        s.setPosition(  pos.x,
                        pos.y);

        sf::Vector2f scale = geometricalContext.getScale();

        s.setScale(scale);

        s.setRotation(geometricalContext.getRotation());

        s.setOrigin(geometricalContext.getOrigin());

        if(animationContext.isValid())
        {
            // If entities is animated,
            // we have to define a subRec
            // corresponding to the current frame animation.

            sf::IntRect intRect;
            const sf::FloatRect& floatRect = animationContext.getFrame();

            intRect.left = int(floatRect.left);
            intRect.top = int(floatRect.top);
            intRect.width = int(floatRect.width);
            intRect.height = int(floatRect.height);

            s.setTextureRect(intRect);
        }

        // Display the sprite.
        GraphicEngine::getInstance()->draw(s);
    }
}
}
