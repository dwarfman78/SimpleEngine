#ifndef Animation_hpp
#define Animation_hpp

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/NonCopyable.hpp>
////////////////////////////////////////////////////////////
namespace se
{
    ////////////////////////////////////////////////////////////
    /// Class embedding animation's duration and frames
    ////////////////////////////////////////////////////////////
    class SE_API Animation
    {
        public:

        Animation();
        Animation(const std::string name, const std::vector<sf::FloatRect> frames, sf::Uint32 duration);
        const std::string& getName() const;

        const   std::vector<sf::FloatRect>&     getFrames()     const;
                sf::Uint32                      getDuration()   const;

        private:
        std::string myName;
        std::vector<sf::FloatRect> myFrames;
        sf::Uint32 myDuration;
    };
}
#endif
