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
            unsigned int renderingPosition() const;
    void cleanParticles();
    unsigned int renderingPosition() const;
    void addTemporaryParticleEntity(float positionX, float positionY, float originX, float originY, float rotation, sf::Int64 duration, const std::string& media, const std::string& animation);
    void addTemporarySoundEntity(const std::string& soundName);
        private:
            std::vector<std::shared_ptr<Renderable> > myRenderables;

    };
}
#endif
