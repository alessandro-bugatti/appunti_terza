#ifndef UDP_SAMPLE_SERVER_H
#define UDP_SAMPLE_SERVER_H

#include <string>
#include "DatagramSocket.h"

namespace simple {
    constexpr int STANDARD_PORT = 8899;
    constexpr int MAX_SIZE = 2048;

    /**
     * Simple class to manage sending and receving UDP packet.
     * Typical use case: creating a game that can be played on
     * a network, i.e. a card game where it should be not possible
     * to watch the other player cards
     */
    class UDP_Communicator {
        DatagramSocket *s;
        std::string message;
        bool received;
        std::string sender_ip;
        void error();
    public:
        /**
         * Create an object to send packets to a particular
         * address/port. The be blocking or not blocking
         *
         * @param server_address
         * @param blocking
         * @param port
         */
        explicit UDP_Communicator(const std::string &server_address, bool blocking = false, unsigned int port = STANDARD_PORT);

        UDP_Communicator(): s(nullptr), received(false) {
        }

        void setParameters(const std::string &server_address, bool blocking = false, unsigned int port = STANDARD_PORT);

        void send(const std::string &message);

        bool incomingMessage();

        std::string getMessage();

        std::string getSenderIP();
    };

} // simple

#endif //UDP_SAMPLE_SERVER_H
