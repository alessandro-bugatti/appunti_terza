#include <sstream>
#include "UDP_Server.h"

#include <iostream>


namespace simple {
    Server::Server() {
        server = new UDP_Communicator();
    }

    void Server::run() {
        std::cout << "Server started at " << server->getHostname() << std::endl;
        while(true) {
            if (server->incomingMessage()) {
                std::string message = server->getMessage();
                std::string sender_IP = server->getSenderIP();
                std::cout << sender_IP << " : " << message << std::endl;
                UDP_Communicator client(sender_IP);
                if (clients.find(sender_IP) == clients.end()) {
                    clients.insert({sender_IP, client});
                    std::cout << "Inserito " << sender_IP << std::endl
                    << "Attualmente presenti " << clients.size()
                    << " utenti collegati." << std::endl;
                }
                for (auto client: clients) {
                    if (client.first != sender_IP) {
                        server->send(message, client.first);
                        std::cout << "Messaggio inviato a " << client.first << std::endl;
                    }
                }
            }
        }
    }
} // simple