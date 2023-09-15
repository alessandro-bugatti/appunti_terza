#include <iostream>

std::string trim(const std::string &s){
    int inizio = 0, fine = s.size() - 1;
    while (inizio < s.size() && s.at(inizio) == ' ')
        inizio++;
    if (inizio == s.size())
        return "";
    while(s.at(fine) == ' ')
        fine--;
    std::string risultato = s;
    risultato.erase(fine + 1, risultato.size() - fine - 1);
    risultato.erase(0, inizio);
    return risultato;
}

int main() {
    std::string linea;
    std::cout << "Inserisci una stringa" << std::endl;
    std::getline(std::cin , linea);
    std::cout << "Gli asterischi evidenziano la presenza degli spazi, altrimenti invisibili" << std::endl;
    std::cout <<"Originale: *" << linea << "*" << std::endl;
    std::cout <<"Dopo il trim: *" << trim(linea) << "*" << std::endl;

    return 0;
}
