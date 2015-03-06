#include <SimpleEngine/Network/UdpClient.hpp>

namespace se
{
    UdpClient::UdpClient(const sf::IpAddress serverIp, unsigned short serverPort)
            : mServerIp(serverIp), mServerPort(serverPort), mConnected(false)
    {
    }

    bool UdpClient::connect()
    {
        // if not connected we connect
        if (!isConnected())
        {
            // prepare socket for receiving packet from server.
            mSocket.setBlocking(false);

            // send hello packet
            sf::Packet helloPacket = NetworkUtils::helloPacket();
            send(helloPacket);

            // restart the clock
            mTimeout.restart();

            // wait for the ack from server
            while (mTimeout.getElapsedTime() < sf::seconds(NetworkUtils::DEFAULT_TIMEOUT))
            {
                if(receive() && checkHelloPacket())
                {
                    mConnected = true;
                }
            }
        }

        return isConnected();
    }

    bool UdpClient::checkHelloPacket()
    {
        bool returnValue{false};

        std::string received;

        std::string helloString;

        if(mLastReceivedPacket >> received && NetworkUtils::helloPacket() >> helloString)
        {
            returnValue = helloString.compare(received) == 0;
        }

        return returnValue;
    }

    bool UdpClient::receive()
    {
        bool returnValue{false};

        sf::IpAddress remoteAddr;

        unsigned short remotePort;

        if(mSocket.receive(mLastReceivedPacket, remoteAddr, remotePort) == sf::UdpSocket::Status::Done)
        {
            // return true if received packet comes from server as it might come from unknown source.
            returnValue = remoteAddr.toString().compare(mServerIp.toString()) == 0 && remotePort == mServerPort;
        }
        return returnValue;
    }

    void UdpClient::disconnect()
    {
        if(isConnected())
        {
            sf::Packet bye = NetworkUtils::byePacket();
            send(bye);
        }
    }

    void UdpClient::send(sf::Packet& packet)
    {
        if(isConnected())
        {
            mSocket.send(packet, mServerIp, mServerPort);
        }
    }
}