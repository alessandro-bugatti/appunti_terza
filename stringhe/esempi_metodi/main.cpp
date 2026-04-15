#include <iostream>

int main() {
    std::string s, cercata;
    //Test di esempio per il metodo find
    s = "La mattina mi sono svegliato tardi.";
    cercata = "tardi";
    std::cout << s.find(cercata) << std::endl;
    std::string assente = "mela";
    std::cout << s.find(assente) << std::endl;
    if (s.find("pera") == std::string::npos) {
        std::cout << "La stringa non è presente" << std::endl;
    }
    s = "La mattina mi sono svegliato e mi sono dimenticato le chiavi.";
    cercata = "sono";
    std::cout << s.find(cercata) << std::endl;
    int pos = 0;
    while (s.find(cercata, pos) != std::string::npos) {
        std::cout << s.find(cercata, pos) << std::endl;
        pos = s.find(cercata, pos) + 1;
    }
    //Test di esempio per il metodo substr
    std::cout << s.substr(11) << std::endl;
    std::cout << s.substr(11, 13) << std::endl;


    return 0;
}
