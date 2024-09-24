//
// Created by alex on 02/07/2022.
//

#include <sstream>
#include "UDP_Communicator.h"



namespace simple {
    class socket_exception: public std::exception
    {
        virtual const char* what() const throw()
        {
            return "No socket established";
        }
    };

    UDP_Communicator::UDP_Communicator(const std::string &address, bool blocking, unsigned int _port) {
        s = nullptr;
        setParameters(address, blocking, _port);
    }

    UDP_Communicator::UDP_Communicator() {
        s = new DatagramSocket(STANDARD_PORT);
    }

    void UDP_Communicator::error() {
        throw new socket_exception;
    }

    void UDP_Communicator::setParameters(const std::string& address, bool blocking, unsigned int _port) {
        if (s != nullptr)
            delete s;
        s = new DatagramSocket(_port, address.c_str(), blocking, TRUE, TRUE);
        received = false;
    }

    void UDP_Communicator::send(const std::string &message, const std::string address){
        if (s == nullptr) {
            error();
        }
        if (address == "")
            //Il +1 serve per includere il terminatore di stringa
            s->send(message.c_str(), message.size() + 1);
        else
            s->sendTo(message.c_str(), message.size() + 1, address.c_str());
    }

    bool UDP_Communicator::incomingMessage() {
        if (s == nullptr) {
            error();
        }
        std::string str;
        char msg[MAX_SIZE];
        int size = s->receive(msg,MAX_SIZE);
        if (size != -1) {
            msg[size] = '\0';
            message = msg;
            received = true;
            sender_ip = s->received_from();
            return true;
        }
        return false;
    }

    std::string UDP_Communicator::getMessage() {
        if (s == nullptr) {
            error();
        }
        if (received) {
            received = false;
            return message;
        }
        return "";
    }

    std::string UDP_Communicator::getSenderIP() {
        if (s == nullptr) {
            error();
        }
        return sender_ip;
    }

    std::string UDP_Communicator::getHostname() {
        return s->getHostname();
    }
} // simple