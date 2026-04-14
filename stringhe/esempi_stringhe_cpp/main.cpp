#include <iostream>

void esempio_cin() {
    //cin ottimo per parole singole, perché permette anche di
    //leggere numeri, ma non va bene per le frasi
    std::string s, t;
    std::cout << "Inserisci una parola: ";
    std::cin >> s;
    std::cout << "Hai inserito la parola " << s << std::endl;
    std::cout << "Inserisci un'altra parola: ";
    std::cin >> t;
    std::cout << "Hai inserito la parola " << t << std::endl;

    int n;
    std::cout << "Inserisci un numero: ";
    std::cin >> n;
    std::cout << "Hai inserito il numero " << n << std::endl;
}

void esempio_cin_getline() {
    int n;
    std::cout << "Inserisci un numero: ";
    std::cin >> n;
    std::cout << "Il numero inserito è " << n << std::endl;
    std::string s;
    std::cout << "Inserisci una frase: ";
    std::getline(std::cin, s);
    std::cout << "Hai inserito: " << s << std::endl;
}

int main() {
    std::string s, sn;
    std::cout << "Inserisci una frase: ";
    std::getline(std::cin, s);
    std::cout << "Hai inserito: " << s << std::endl;

    std::cout << "Inserisci un numero: ";
    std::getline(std::cin, sn);
    std::cout << "Hai inserito: " << sn << std::endl;
    int n = std::stoi(sn);

    int risultato = n * 4;
    std::cout << "Il numero inserito moltiplicato per 4 fa "
        << risultato << std::endl;

    std::cout << "Il " << n << "-esimo carattere di "
    << s << " è " << s.at(n) << std::endl;

    return 0;
}
