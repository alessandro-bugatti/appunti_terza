#include <iostream>
#include <fstream>


int estrai(std::string s) {
    int risultato;
    int prima, seconda;

    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) >= '0' && s.at(i) <= '9'){
            prima = s.at(i) - '0';
            break;
        }
    }
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s.at(i) >= '0' && s.at(i) <= '9'){
            seconda = s.at(i) - '0';
            break;
        }
    }
    risultato = prima*10 + seconda;
    return risultato;
}
int main() {
    std::ifstream in("input.txt");
    std::string s;
    int somma = 0;
    std::cout << estrai("adfdf1fhgf5ghjgj7jgj") << std::endl;
    for (int i = 0; i < 1000; ++i) {
        in >> s;
        somma += estrai(s);
    }

    std::cout << somma << std::endl;
    return 0;
}

