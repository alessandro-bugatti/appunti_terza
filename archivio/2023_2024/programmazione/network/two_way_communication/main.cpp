#include <iostream>

#include "src/UDP_Communicator.h"

int main(int argc, char *argv[]) {
    bool done = false;
    std::string address;
    if (argc > 2) {
        std::cout << "Usage " << argv[0] << " " << " ip_address";
        return 1;
    }
    if (argc == 1) {
        std::cout << "Inserisci l'indirizzo IP del computer con cui vuoi comunicare: ";
        std::cin >> address;
    }
    else
        std::string address = argv[1];
    //Client creation
    simple::UDP_Communicator client(address);

    //Sending a message to a server
    std::string message = "Hello";
    client.send(message);
    std::cout << "Invio del saluto a " << address << std::endl;

    //Listening to receive a message until exit
    while(!done) {
        if(client.incomingMessage()) {
            std::string received = client.getMessage();
            if (received == "exit") {
                std::cout << "L'utente si è tolto dalla comunicazione" << std::endl;
            }
            std::cout << "Messaggio ricevuto da " << client.getSenderIP() << " : " << received << std::endl;
            std::cout << "Scrivi il tuo messaggio: ";
            std::string answer;
            getline(std::cin, answer);
            client.send(answer);
            if (answer == "exit") {
                done = true;
            }
            else{
                std::cout << "In attesa di risposta..." << std::endl;
            }
        }
    };
    return 0;
}
