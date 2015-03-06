#ifndef UdpClient_hpp
#define UdpClient_hpp

#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/NonCopyable.hpp>
#include <SimpleEngine/Network/NetworkUtils.hpp>

namespace se
{
    /*
    * This class handles session (or connection) between a client and a server using an UDP socket.
    */
    class SE_API UdpClient : public NonCopyable
    {
    public:

        /*
         * Constructor.
         *
         * @param serverIp : server ip address.
         * @param serverPort : server port.
         */
        UdpClient(const sf::IpAddress serverIp, unsigned short serverPort);

        /*
         * Connect this client to the defined server.
         */
        bool connect();

        /*
         * Disconnect this client from the defined server.
         */
        void disconnect();

        /*
         * Send a packet to the server.
         */
        void send(sf::Packet& packet);

        /*
         * Receive a packet from the server.
         *
         * @return true if packet is receive from the server, false otherwise.
         */
        bool receive();

        /*
         * Tells if this client is connected or not.
         *
         * @return true if connected false otherwise.
         */
        bool isConnected() const
        {
            return mConnected;
        }

        /*
         * Return the last packet received after receive() is called.
         *
         * @return the last packet receive.
         */
        sf::Packet const &getMLastReceivedPacket() const
        {
            return mLastReceivedPacket;
        }

    private:

        /*
         * Server ip.
         */
        sf::IpAddress mServerIp;

        /*
         * Server port.
         */
        unsigned short mServerPort;

        /*
         * Status of the connection.
         */
        bool mConnected;

        /*
         * Timeout clock.
         */
        sf::Clock mTimeout;

        /*
         * UDP Socket.
         */
        sf::UdpSocket mSocket;

        /*
         * Last received packet.
         */
        sf::Packet mLastReceivedPacket;

        /*
         * This method tells if last received packet is of type "hello packet" (init connection)
         */
        bool checkHelloPacket();

    };
}
#endif