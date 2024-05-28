#ifndef UDP_SERVER_H
#define UDP_SERVER_H

#include <map>
#include <string>
#include "DatagramSocket.h"
#include "UDP_Communicator.h"

namespace simple {
    /**
     * Simple class to manage sending and receving UDP packet.
     * Typical use case: creating a game that can be played on
     * a network, i.e. a card game where it should be not possible
     * to watch the other player cards
     */
    class Server {
        UDP_Communicator *server;
        std::map<std::string, UDP_Communicator> clients;
    public:

     /**
      * Empty constructor, the idea is to use this when
      * the ip address of the destination is not known
      */

        explicit Server();




        /**
         * Run the server
         */
        void run();

    };

} // simple

#endif //UDP_SERVER_H
