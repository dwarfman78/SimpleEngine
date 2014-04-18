#ifndef SoundContext_hpp
#define SoundContext_hpp
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/NonCopyable.hpp>
#include <SimpleEngine/Core/Manager.hpp>
#include <SimpleEngine/Core/Context.hpp>
////////////////////////////////////////////////////////////
namespace se
{
class SE_API SoundContext : public NonCopyable, public Context
{
public:
    SoundContext();

    SoundContext(const std::string& soundName);

    ////////////////////////////////////////////////////////////
    /// \return false if the context is not initialized (no sprite initialized).
    ////////////////////////////////////////////////////////////
    bool isValid() const;

    void setPlayOnce(bool playOnce);

    bool played() const;

    void setPlayed(bool played);

    bool playOnce() const;

    void reset();

    sf::Sound& getSound();

    void setSound(const std::string& soundName, sf::Sound sound);

    const std::string& getCurrentSoundName() const;

private:
    sf::Sound mySound;
    bool myPlayOnce;
    bool myPlayed;
    bool myValid;
    std::string myCurrentSoundName;
};
}
#endif // SoundContext_hpp
