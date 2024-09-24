#ifndef UDP_COMMUNICATOR_H
#define UDP_COMMUNICATOR_H

#include <string>
#include "DatagramSocket.h"

namespace simple {
    constexpr int STANDARD_PORT = 8899; //> The standard port used to send and receive message
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
         * address/port. The blocking or not blocking parameter
         * enable or disable receive blocking behaviour
         *
         * @param destination_address The destination IP address
         * @param blocking If true, the receive is blocking, no blocking otherwise
         * @param port The destination port
         * @warning No check is done both on address or port
         */
        explicit UDP_Communicator(const std::string &destination_address, bool blocking = false, unsigned int port = STANDARD_PORT);

        /**
         * Empty constructor, the idea is to use this when
         * the ip address of the destination is not known
         */
        UDP_Communicator();

        /**
         * This method must be used to set 
         * the parameters of a socket after the empty costructor is used
         * @param server_address
         * @param blocking 
         * @param port 
         */
        void setParameters(const std::string &server_address, bool blocking = false, unsigned int port = STANDARD_PORT);

        /**
         * To send a message to the destination address
         * @param message The message that will be sent
         */
        void send(const std::string &message, const std::string address = "");

        /**
         * Check if there is a message on the configurated port
         * @return true if there is an incoming message, false otherwise
         */
        bool incomingMessage();

        /**
         * Return a receveid message
         * @return The received message
         * @warning It has to be used after receveing a message
         * @code
         * if (udp.isIncoming())
         *    str = udp.getMessage();
         * @endcode
         */
        std::string getMessage();

        /**
         * Return the IP addresse of the sender of a message
         * @return The IP address of the sender
         * @warning It has to be used after receveing a message
         * @code
         * if (udp.isIncoming()){
         *    str = udp.getMessage();
         *    ip = udp.getSenderIP();
         * @endcode
         */
        std::string getSenderIP();

        std::string getHostname();
    };

} // simple

#endif //UDP_COMMUNICATOR_H
