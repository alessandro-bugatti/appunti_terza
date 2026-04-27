#include <iostream>

std::string parola_piu_lunga(const std::string &t) {
    std::string s = t + ' ';
    int conta = 0, max = 0, pos = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) == ' ') {
            if (conta > max) {
                max = conta;
                pos = i - max;
            }
            conta = 0;
        } else {
            conta++;
        }
    }
    return s.substr(pos, max);
}

int main() {
    std::string frase = "Oggi vorrei saltare l'interrogazione di tpi,possibilmente.";
    std::cout << parola_piu_lunga(frase) << std::endl;

    return 0;
}
