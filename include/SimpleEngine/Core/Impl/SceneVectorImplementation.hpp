#ifndef SceneVectorImplementation_hpp
#define SceneVectorImplementation_hpp
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/Core/Scene.hpp>
namespace se
{
    ////////////////////////////////////////////////////////////
    /// std::vector implementation for Scene interface.
    ////////////////////////////////////////////////////////////
    class SE_API SceneVectorImplementation : public Scene
    {
        public:
            SceneVectorImplementation();
            virtual ~SceneVectorImplementation();
            void registerRenderable(std::shared_ptr<Renderable> renderable);
            void unregisterRenderable(std::shared_ptr<Renderable> renderable);
            void render();
            void renderLogic();
            void interpolate(const float interpolation);
            bool unregister() const;
            void cleanRenderables();
        private:
            std::vector<std::shared_ptr<Renderable> > myRenderables;

    };
}
#endif
