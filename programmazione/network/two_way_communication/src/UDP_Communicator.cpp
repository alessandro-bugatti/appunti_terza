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

    void UDP_Communicator::error() {
        throw new socket_exception;
    }

    void UDP_Communicator::setParameters(const std::string& address, bool blocking, unsigned int _port) {
        if (s != nullptr)
            delete s;
        s = new DatagramSocket(_port, address.c_str(), blocking, TRUE, TRUE);
        received = false;
    }

    void UDP_Communicator::send(const std::string &message){
        if (s == nullptr) {
            error();
        }
        //Il +1 serve per includere il terminatore di stringa
        s->send(message.c_str(), message.size() + 1);
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
} // simple