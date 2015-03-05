#ifndef UdpClient_hpp
#define UdpClient_hpp

#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/NonCopyable.hpp>
#include <SimpleEngine/Network/NetworkUtils.hpp>

namespace se
{
    class SE_API UdpClient : public NonCopyable
    {
    public:

        UdpClient(const sf::IpAddress serverIp, unsigned short serverPort);

        bool connect();

        void disconnect();

        void send(sf::Packet& packet);

        bool receive();

        bool isConnected() const
        {
            return mConnected;
        }

        sf::Packet const &getMLastReceivedPacket() const
        {
            return mLastReceivedPacket;
        }

    private:
        sf::IpAddress mServerIp;

        unsigned short mServerPort;

        bool mConnected;

        sf::Clock mTimeout;

        sf::UdpSocket mSocket;

        sf::Packet mLastReceivedPacket;

        bool checkHelloPacket();

    };
}
#endif