#ifndef SceneSetImplementation_hpp
#define SceneSetImplementation_hpp
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/Core/Scene.hpp>
#include <SimpleEngine/Core/Entity.hpp>
#include <SimpleEngine/Physics/PhysicBodyManager.hpp>
#include <SimpleEngine/Physics/RaycastNearestCallback.hpp>
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

    std::shared_ptr<Entity> addTemporaryParticleEntity(float positionX, float positionY, float originX, float originY, float rotation, sf::Int64 duration, const std::string& media, const std::string& animation);

    std::shared_ptr<Entity>  addTemporaryPhysicParticle(float positionX, float positionY, float originX, float originY, float rotation, sf::Int64 duration, const std::string& media, const std::string& body);

    std::shared_ptr<Entity>  addTemporarySoundEntity(const std::string& soundName);

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

    b2World& getPhysicWorld() {return myPhysicWorld;};

    b2Body* getGround() {return myGround;};

    void makeExplosion(const b2Vec2& center, float radius, float power);
private:
    std::set< std::shared_ptr<Renderable>, std::function<bool(std::shared_ptr<Renderable>, std::shared_ptr<Renderable>)> > myRenderables;

    ////////////////////////////////////////////////////////////
    /// Music
    ////////////////////////////////////////////////////////////
    sf::Music myMusic;
    ////////////////////////////////////////////////////////////

    b2World myPhysicWorld;

    b2Body* myGround;

};
}
#endif
