#include <iostream>
#include <vector>

bool ricerca(const std::string& s, char c) {
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) == c) {
            return true;
        }
    }
    return false;
}

/**
 *
 * @param attuale Ci si aspetta che attuale.size == segreta.size
 * @param segreta
 * @param c
 */
void svela(std::string& attuale, const std::string& segreta, char c) {
    for (int i = 0; i < segreta.size(); ++i) {
        if (segreta.at(i) == c) {
            attuale.at(i) = c;
        }
    }
}

std::string scelta_parola(const std::vector<std::string>& parole) {
    return parole.at(rand()%parole.size());
}

int main() {
    std::vector<std::string> parole;
    //Qua andrà il codice che le legge da un file
    parole.push_back("cancello");
    parole.push_back("albero");
    parole.push_back("lavagna");
    parole.push_back("vaso");

    int lunghezza = parole.size();
    std::string segreta = scelta_parola(parole);
    std::string indovinata;
    for (int i = 0; i < segreta.size(); ++i) {
        indovinata += '_';
    }
    std::cout << ricerca(segreta, 'c') << std::endl;
    std::cout << ricerca(segreta, 'i') << std::endl;
    svela(indovinata, segreta, 'l');
    std::cout << indovinata << std::endl;
    return 0;
}
