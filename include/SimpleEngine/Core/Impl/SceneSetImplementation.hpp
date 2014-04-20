#ifndef SceneSetImplementation_hpp
#define SceneSetImplementation_hpp
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/Core/Scene.hpp>
namespace se
{
    ////////////////////////////////////////////////////////////
    /// std::set implementation for Scene interface.
    ////////////////////////////////////////////////////////////
    class SE_API SceneSetImplementation : public Scene
    {
        public:
            SceneSetImplementation();
            virtual ~SceneSetImplementation();
            void registerRenderable(std::shared_ptr<Renderable> renderable);
            void unregisterRenderable(std::shared_ptr<Renderable> renderable);
            void render();
            void renderLogic();
            void interpolate(const float interpolation);
            bool unregister() const;
            void cleanRenderables();
        private:
            std::set<std::shared_ptr<Renderable> > myRenderables;

    };
}
#endif
