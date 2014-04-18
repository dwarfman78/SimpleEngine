#include <SimpleEngine/Graphic/GraphicEngine.hpp>
namespace se
{
    GraphicEngine* GraphicEngine::getInstance()
    {
        return Singleton<GraphicEngine>::getInstance();
    }
    GraphicEngine::GraphicEngine()
    {
        ;
    }
    sf::RenderWindow& GraphicEngine::getRenderWindow()
    {
        return myRenderWindow;
    }
    void GraphicEngine::draw(const sf::Uint32 d)
    {

    }
    void GraphicEngine::draw(const sf::Sprite& s)
    {
        myRenderWindow.draw(s);
    }
    void GraphicEngine::draw(const sf::Text& text)
    {
        myRenderWindow.draw(text);
    }
    void GraphicEngine::setShowFps(const bool b)
    {
        myShowFps = b;
    }
    bool GraphicEngine::isShowFps() const
    {
        return myShowFps;
    }
}

