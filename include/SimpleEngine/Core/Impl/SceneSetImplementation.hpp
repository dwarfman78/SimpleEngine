#ifndef SceneSetImplementation_hpp
#define SceneSetImplementation_hpp
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/Core/Scene.hpp>
#include <SimpleEngine/Core/Entity.hpp>
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

    unsigned int renderingPosition() const;
    void addTemporaryParticleEntity(float positionX, float positionY, float originX, float originY, float rotation, sf::Int64 duration, const std::string& media, const std::string& animation);
    void addTemporarySoundEntity(const std::string& soundName);

    ////////////////////////////////////////////////////////////
    /// Load a music from its filename.
    ////////////////////////////////////////////////////////////
    void loadMusic(const std::string& fileName);

    ////////////////////////////////////////////////////////////
    /// Play current music.
    ////////////////////////////////////////////////////////////
    void playMusic();

    ////////////////////////////////////////////////////////////
    /// Pause current music.
    ////////////////////////////////////////////////////////////
    void pauseMusic();

    ////////////////////////////////////////////////////////////
    /// Get current sf::Music.
    ////////////////////////////////////////////////////////////
    const sf::Music& getCurrentMusic() const;
private:
    std::set< std::shared_ptr<Renderable>, std::function<bool(std::shared_ptr<Renderable>, std::shared_ptr<Renderable>)> > myRenderables;

    ////////////////////////////////////////////////////////////
    /// Music
    ////////////////////////////////////////////////////////////
    sf::Music myMusic;
    ////////////////////////////////////////////////////////////

};
}
#endif
