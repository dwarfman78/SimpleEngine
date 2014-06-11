#ifndef SoundPool_hpp
#define SoundPool_hpp
#include <SimpleEngine/ToolBox/Singleton.hpp>
#include <SimpleEngine/Core/Manager.hpp>
#include <SimpleEngine/myConsts.hpp>
namespace se
{

    ////////////////////////////////////////////////////////////
    /// Class of sf::Sound pool.
    ////////////////////////////////////////////////////////////
    class SE_API SoundPool : public Singleton<SoundPool>
    {
        friend class Singleton<SoundPool>;

        public:
        static SoundPool* getInstance(){return Singleton<SoundPool>::getInstance();};

        ////////////////////////////////////////////////////////////
        /// Get Sound from its name.
        /// \return sf::Sound ptr or nullptr if no sound is available.
        ////////////////////////////////////////////////////////////
        std::shared_ptr<sf::Sound> getSound(const std::string& soundName);

        void releaseSound(const std::string& soundName, std::shared_ptr<sf::Sound> sound);

        private:

        std::map<std::string, std::stack<std::shared_ptr<sf::Sound> > > mySounds;

    };
}
#endif // SoundPool_hpp
