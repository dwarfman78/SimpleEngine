#ifndef NetworkUtils_hpp
#define NetworkUtils_hpp

#include <SimpleEngine/myImports.hpp>

namespace se
{
    class SE_API NetworkUtils
    {
    public:
        static constexpr float DEFAULT_TIMEOUT = 10.f;

        static sf::Packet helloPacket(){sf::Packet returnValue; returnValue << "HELLO"; return returnValue; }

        static sf::Packet byePacket(){sf::Packet returnValue; returnValue << "BYE"; return returnValue; }

    private:
        NetworkUtils();
    };
}
#endif