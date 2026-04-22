#include <iostream>
#include <vector>
#include <pstl/execution_defs.h>

/**
 * Versione semplice in cui si suppone che la
 * frase sia spaziata correttamente
 * @param frase Esempio: oggi sono andato al mare, poi sono tornato a casa
 * @return il numero di parole
 */
int conta_parole(const std::string& frase) {
    int conta = 0;
    for (int i = 0; i < frase.size(); ++i) {
        if (frase.at(i) == ' ') {
            conta++;
        }
    }
    return conta + 1;
}

void censura_parola(std::string &frase, const std::string &p) {
    int pos = 0;
    while ((pos = frase.find(p, pos)) != std::string::npos) {
        std::string s;
        for (int i = 0; i < p.size() - 2; ++i) {
            s += '*';
        }
        frase.replace(pos + 1, p.size() - 2, s);
    }
}

std::vector<std::string> filtra_nomi(const std::vector<std::string> &parole) {
    std::vector<std::string> risultato;
    for (int i = 0; i < parole.size(); ++i) {
        if (parole.at(i).at(0) >= 'A' &&
            parole.at(i).at(0) <= 'Z') {
            risultato.push_back(parole.at(i));
        }
    }
    return risultato;
}

int main() {
    std::cout << conta_parole("ciao a tutti") << std::endl;
    std::string frase = "Se sei stupido sei stupido";
    censura_parola(frase, "stupido");
    std::cout << frase << std::endl;
    std::vector<std::string> parole;
    parole.push_back("Carlo");
    parole.push_back("matita");
    parole.push_back("dentifricio");
    parole.push_back("Luca");
    parole.push_back("Maria");


    return 0;
}
