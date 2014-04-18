#include <SimpleEngine/Graphic/WriteStrategy.hpp>
namespace se
{
void WriteStrategy::render(RenderingContext& rc)
{
    // Getting contexts.
    GeometricalContext& geometricalContext = rc.getGeometricalContext();
    WriteContext& writeContext = rc.getWriteContext();

    if(geometricalContext.isValid()&&writeContext.isValid())
    {
        // if contexts are valid, we get the text.
        sf::Text& text = writeContext.getText();

        // set position and scale from geometrical context.
        text.setPosition(  geometricalContext.getPosition().x,
                           geometricalContext.getPosition().y);

        text.setScale(geometricalContext.getScale());

        text.setOrigin(geometricalContext.getOrigin());

        text.setRotation(geometricalContext.getRotation());

        GraphicEngine::getInstance()->draw(text);
    }


}
}

