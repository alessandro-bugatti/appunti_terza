#include <iostream>

int main() {
    std::string email;
    std::cout << "Inserisci l'email";
    getline(std::cin, email);

    int pos = email.find("@") + 1;

    std::string dominio = email.substr(pos);

    std::cout << "Il dominio e' " << dominio;
//prima versione con problemi se il dominio ha piu punti al suo interno
    int pos_punto = email.find(".", pos) + 1;
    //seconda versione cerca la posizione del punto partendo dal fondo
    int i = email.size() - 1;
    while (email.at(i) != '.') {
        i--;
    }
    pos_punto = i + 1;
    std::string punto = email.substr(pos_punto);

    std::cout << std::endl << "Il dominio di primo livello e " << punto;

    return 0;
}