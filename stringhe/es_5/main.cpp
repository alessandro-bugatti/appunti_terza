#include <iostream>

bool carattere(char c) {
    return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}

char minuscolo(char c) {
    
}



std::string pulisci_stringa(const std::string &t) {
    std::string supporto;
    for (int i = 0; i < t.size(); ++i) {
        if (carattere(t.at(i))) {
            supporto += minuscolo(t.at(i));
        }
    }
    return supporto;
}

int main() {
    std::string frase = "Oggi vorrei saltare l'interrogazione di tpi,possibilmente.";
    std::cout << pulisci_stringa(frase) << std::endl;

    return 0;
}
