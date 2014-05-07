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
void GraphicEngine::init()
{
    myRenderTexture.create(myRenderWindow.getSize().x,myRenderWindow.getSize().y);
    myRenderTexture.setSmooth(true);
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
    myRenderTexture.draw(s);
}
void GraphicEngine::draw(const sf::Text& text)
{
    myRenderTexture.draw(text);
}
void GraphicEngine::setShowFps(const bool b)
{
    myShowFps = b;
}
bool GraphicEngine::isShowFps() const
{
    return myShowFps;
}
sf::RenderTexture& GraphicEngine::getRenderTexture()
{
    return myRenderTexture;
}
void GraphicEngine::applyShader(const std::string& fileName)
{
    if(shader.isAvailable())
    {
        if(shader.loadFromFile(fileName,sf::Shader::Fragment))
        {
            myRenderTexture.draw(sf::Sprite(myRenderTexture.getTexture()),&shader);

            myRenderTexture.display();
        }
        else
        {
            std::cout << "cannot load shader " + fileName << std::endl;
        }
    }
    else
    {
        std::cout << "shaders unavailable" << std::endl;
    }
}
}

