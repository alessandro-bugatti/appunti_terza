#include <iostream>

void inizializza(const std::string &segreta, std::string& attuale) {
    attuale = "";
    for (int i = 0; i < segreta.size(); ++i) {
        attuale += '_';
    }
}

bool controlla(const std::string& segreta, char lettera,
    std::string &attuale) {
    bool trovata = false;
    for (int i = 0; i < segreta.size(); ++i) {
        if (segreta.at(i) == lettera) {
            attuale.at(i) = lettera;
            trovata = true;
        }
    }
    return trovata;
}

std::string lettere_usate(const std::string& provate) {
    std::string s;
    for (int i = 0; i < provate.size(); ++i) {
        s += provate.at(i);
        s += ", ";
    }
    return s;
}

int main() {
    const int MAX_ERRORI = 6;
    int conta_errori = 0;
    std::string segreta, provate, attuale;

    segreta = "armadio";
    inizializza(segreta, attuale);
    while (conta_errori < MAX_ERRORI && segreta != attuale) {
        std::cout << attuale << std::endl;
        std::cout << "Numero di errori: " << conta_errori << std::endl;
        char lettera;
        std::cout << "Inserisci una lettera: ";
        std::cin >> lettera;
        provate += lettera;
        if (!controlla(segreta, lettera, attuale)) {
            conta_errori++;
        }
        std::string temp = lettere_usate(provate);
        std::cout << "Lettere provate: " << temp << std::endl;
    }
    if (segreta == attuale) {
        std::cout << "Hai indovinato la parola " << segreta << std::endl;
    }
    else {
        std::cout << "Hai sbagliato, la parola era " << segreta << std::endl;
    }
    return 0;
}