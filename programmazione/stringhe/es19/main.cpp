#include <iostream>

bool simbolo_valido(char c) {
    std::string valide = "ACGTacgt";
    if (valide.find(c) == std::string::npos)
        return false;
    return true;
}

bool dna_valido(const std::string& dna) {
    for (int i = 0; i < dna.size(); ++i) {
        if (!simbolo_valido(dna.at(i)))
            return false;
    }
    return true;
}

int occorrenze(const std::string& S, const std::string& T) {
    if (!dna_valido(S))
        return -1;
    if (!dna_valido(T))
        return -1;
}

int main() {
    char c = tolower('9');
    std::cout << c << std::endl;
    return 0;
}