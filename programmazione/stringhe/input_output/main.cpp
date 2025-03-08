#include <iostream>

int main() {
    std::string s;
    /* Utilizzo di cin per la lettura, con i suoi problemi
    std::cout << "Inserisci un nome: ";
    std::cin >> s;
    std::cout << "Hai inserito la stringa " << s << std::endl;
    int n;
    std::cout << "Inserisci un numero: ";
    std::cin >> n;
    std::cout << "Hai inserito il numero " << n << std::endl;
    */

    /* Utilizzo di getline e problema con la cin
    int n;
    std::cout << "Inserisci un numero: ";
    std::cin >> n;
    std::cout << "Hai inserito il numero " << n << std::endl;

    std::cout << "Inserisci una frase: ";
    std::getline(std::cin, s);
    std::cout << "Hai scritto la frase " << s << std::endl;
    */

    int n;
    std::string temp;
    std::cout << "Inserisci un numero: ";
    std::getline(std::cin, temp);
    n = std::stoi(temp);
    std::cout << "Hai inserito il numero " << n << std::endl;

    std::cout << "Inserisci una frase: ";
    std::getline(std::cin, s);
    std::cout << "Hai scritto la frase " << s << std::endl;

    for (int i = 0; i < s.size(); ++i) {
        std::cout << "pos " << i << " -> " << s.at(i)
            << std::endl;
    }


    return 0;
}