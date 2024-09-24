#include <iostream>
#include <string>

int main() {
    char c = 'a';
    std::string s = "ciao";
    int n = 97;
    std::string ns = "97";
    //Attenzione: il fatto che n e ns vengano stampate uguali
    //non vuol dire che sono la stessa cosa
    std::cout << n << " " << ns << std::endl;

    std::string parola = "Hello";//72ello

    std::string modificata;

    //Primo modo
    modificata = std::to_string((int)parola.at(0)) + parola.substr(1);
    std::cout << modificata << std::endl;
    //Secondo modo
    modificata = parola;
    modificata.replace(0,1,std::to_string((int)modificata.at(0)));
    std::cout << modificata << std::endl;
    //Terzo modo
    char primoCarattere = parola.at(0);
    parola.erase(0,1);
    parola.insert(0,std::to_string((int)primoCarattere));

    std::cout << parola << std::endl;

    std::string frase;
    std::cout << "Inserisci un numero: ";
    std::getline(std::cin, frase);

    int numero = std::stoi(frase);

    return 0;
}
