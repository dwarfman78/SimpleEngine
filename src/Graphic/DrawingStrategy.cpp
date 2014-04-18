#include <SimpleEngine/Graphic/DrawingStrategy.hpp>
namespace se
{
void DrawingStrategy::render(RenderingContext& rc)
{
    Logger log("DrawingStrategy::render::"+se::Utils::toString(this));

    // Get contexts from global context.
    AnimationContext& animationContext = rc.getAnimationContext();
    DrawingContext& drawingContext = rc.getDrawingContext();
    GeometricalContext& geometricalContext = rc.getGeometricalContext();

    if(geometricalContext.isValid()&&drawingContext.isValid())
    {// if basic needed contexts are initialized

        // Get sprite from drawing context.
        sf::Sprite& s = drawingContext.getSprite();

        log << "Contexts valid, proceeding with drawing of sprite : " << se::Utils::toString(&s);

        sf::Vector3f pos = geometricalContext.getPosition();

        log << "\t drawing sprite at : " + se::Utils::toString(pos.x) + " " + se::Utils::toString(pos.y);

        // Set position and scale from geometric context.
        s.setPosition(  pos.x,
                        pos.y);

        sf::Vector2f scale = geometricalContext.getScale();

        log << "\t scale : " + se::Utils::toString(scale.x) + " " + se::Utils::toString(scale.y);

        s.setScale(scale);

        log << "\t rotation : " + se::Utils::toString(geometricalContext.getRotation());

        s.setRotation(geometricalContext.getRotation());

        s.setOrigin(geometricalContext.getOrigin());

        if(animationContext.isValid())
        {
            log << "\t animation context valid, proceeding";
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
