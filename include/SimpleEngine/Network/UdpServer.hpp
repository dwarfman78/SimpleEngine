#ifndef UdpServer_hpp
#define UdpServer_hpp

#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/NonCopyable.hpp>

namespace se
{
    class SE_API UdpServer : NonCopyable
    {
    public:
        UdpServer(unsigned short port);
    private:
        unsigned short mPort;
        sf::UdpSocket mSocket;

    };
}
#endif