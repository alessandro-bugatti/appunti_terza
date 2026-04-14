#include <iostream>
#include <vector>

std::string estrai() {
    std::vector<std::string> parole;
    parole.push_back("salvietta");
    parole.push_back("aereo");
    parole.push_back("bigliardo");
    parole.push_back("lanterna");
    return parole.at(rand() % parole.size());
}

void sostituisci(std::string &parola, char lettera, const std::string &segreta){
    for (int i = 0; i < parola.size(); ++i) {
        if (segreta.at(i) ==  lettera) {
            parola.at(i) = lettera;
        }
    }
}

void reset(std::string &parola, std::string &segreta, std::string &uscite, int &n_errori) {
    n_errori = 0;
    segreta = estrai();
    parola = "";
    for (int i = 0; i < segreta.size(); ++i) {
        parola += '_';
    }
    uscite = "";
}

bool indovinata(const std::string &parola, const std::string &segreta) {
    return parola == segreta;
}

bool lettera_corretta(char c) {
    return 'a' <= c && c <= 'z';
}

void lettere_uscite(std::string &uscite, char c) {
    if (uscite.size() > 0) {
        uscite = uscite + "," + c;
    } else {
        uscite = c;
    }
}

int main() {
    std::string parola, segreta, uscite;
    int n_errori;
    reset(parola, segreta, uscite, n_errori);
    const int MAX_ERRORI = 5;
    while (!indovinata(parola, segreta) && n_errori < MAX_ERRORI) {
        std::cout << parola << std::endl;
        std::cout << "Lettere già uscite: " << uscite << std::endl;
        std::cout << "Inserisci una lettera: ";
        char l;
        std::cin >> l;
        while (!lettera_corretta(l)) {
            std::cout << "Errore, reinserisci una lettera: ";
            std::cin >> l;
        }
        sostituisci(parola, l, segreta);
        lettere_uscite(uscite, l);
    }
    return 0;
}


