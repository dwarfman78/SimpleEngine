#ifndef Scene_hpp
#define Scene_hpp
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/Core/Renderable.hpp>
#include <SimpleEngine/ToolBox/NonCopyable.hpp>
////////////////////////////////////////////////////////////
namespace se
{
    ////////////////////////////////////////////////////////////
    /// Scene interface.
    ////////////////////////////////////////////////////////////
    class SE_API Scene : public NonCopyable, public Renderable
    {
        public:
            ////////////////////////////////////////////////////////////
            /// See Renderable.
            ////////////////////////////////////////////////////////////
            virtual void registerRenderable(std::shared_ptr<Renderable> renderable) = 0;
            virtual void unregisterRenderable(std::shared_ptr<Renderable> renderable) = 0;
            virtual void cleanRenderables() = 0;
            virtual void render() = 0;
            virtual void renderLogic() = 0;
            virtual void interpolate(const float interpolation) = 0;
            ////////////////////////////////////////////////////////////

    };
}
#endif // Scene_hpp
