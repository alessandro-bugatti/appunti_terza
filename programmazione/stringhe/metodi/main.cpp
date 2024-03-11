#include <iostream>
#include <string>

int main() {
    std::string s = "La penna è sul tavolo";
    //Ricerca semplice a partire dall'inizio della stringa
    int pos = s.find("tavolo");
    std::cout << "La parola si trova in posizione " << pos << std::endl;
    //s.at(pos) = 'c';
    std::cout << s << std::endl;
    s += " e il tavolo è fatto di legno.";
    std::cout << s << std::endl;
    //Ricerca a partire da una posizione diversa dall'inizio
    pos = s.find("tavolo", 18);
    std::cout << "La parola si trova in posizione " << pos << std::endl;
    //Cosa succede se la stringa non è presente
    pos = s.find("cavolo");
    std::cout << "cavolo di trova in posizione " << pos << std::endl;
    if (pos == std::string::npos){
        std::cout << "La parola cavolo qunidi non è presente." << std::endl;
    }
    return 0;
}
