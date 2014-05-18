#ifndef Scene_hpp
#define Scene_hpp
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/Core/Renderable.hpp>
#include <SimpleEngine/Core/Entity.hpp>
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
    virtual void render() = 0;
    virtual void renderLogic() = 0;
    virtual void interpolate(const float interpolation) = 0;
    ////////////////////////////////////////////////////////////
    virtual void registerRenderable(std::shared_ptr<Renderable> renderable) = 0;
    virtual void unregisterRenderable(std::shared_ptr<Renderable> renderable) = 0;
    virtual void cleanRenderables() = 0;

    ////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////
    /// Load a music from its filename.
    ////////////////////////////////////////////////////////////
    virtual void loadMusic(const std::string& fileName) = 0;

    ////////////////////////////////////////////////////////////
    /// Play current music.
    ////////////////////////////////////////////////////////////
    virtual void playMusic()= 0;

    ////////////////////////////////////////////////////////////
    /// Pause current music.
    ////////////////////////////////////////////////////////////
    virtual void pauseMusic()= 0;

    ////////////////////////////////////////////////////////////
    /// Get current sf::Music.
    ////////////////////////////////////////////////////////////
    virtual const sf::Music& getCurrentMusic() const = 0;

    virtual b2Body* getGround() = 0;

    ////////////////////////////////////////////////////////////
    /// Add a particle entity, particle entities are normal entities
    /// automatically removed from the scene.
    /// //TODO needs rework because this method's signature is so ugly
    ////////////////////////////////////////////////////////////
    virtual std::shared_ptr<Entity> addTemporaryParticleEntity(float positionX, float positionY, float originX, float originY, float rotation, sf::Int64 duration, const std::string& media, const std::string& animation) = 0;

    virtual std::shared_ptr<Entity> addTemporarySoundEntity(const std::string& soundName) = 0;

    virtual std::shared_ptr<Entity> addTemporaryPhysicParticle(float positionX, float positionY, float originX, float originY, float rotation, sf::Int64 duration, const std::string& media, const std::string& body) = 0;

    virtual b2World& getPhysicWorld() = 0;

};
}
#endif // Scene_hpp
