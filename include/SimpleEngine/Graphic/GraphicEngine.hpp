#ifndef GraphicEngine_h
#define GraphicEngine_h
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/Singleton.hpp>
#include <SimpleEngine/ToolBox/Utils.hpp>
namespace se
{
    ////////////////////////////////////////////////////////////
    /// Class to manage 2D rendering
    ////////////////////////////////////////////////////////////
    class SE_API GraphicEngine : public Singleton<GraphicEngine>
    {
        friend class Singleton<GraphicEngine>;

        private:

        ////////////////////////////////////////////////////////////
        /// Constructor
        ////////////////////////////////////////////////////////////
        GraphicEngine();

        public:

        static GraphicEngine* getInstance();

        sf::RenderWindow& getRenderWindow();

        void draw(const sf::Uint32 d);

        void draw(const sf::Text& text);

        void draw(const sf::Sprite& s);

        void setShowFps(const bool b);

        bool isShowFps() const;

        private:

        sf::RenderWindow myRenderWindow;

        bool myShowFps;

    };
}
#endif