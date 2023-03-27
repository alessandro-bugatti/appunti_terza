#include <iostream>

int main() {
    //Esempi con find
    std::string s = "Sono andato a mangiare e poi sono andato dal nonno.";
    int pos;
    pos = s.find("andato");
    std::cout << "La parola è stata trovata in posizione: " << pos << std::endl;
    pos = s.find("sono");
    std::cout << pos << std::endl;

    //Esempio di ricerca di più occorrenze
    std::string cercata = "no";
    int conta_occorrenze = 0;
    pos = 0;
    while((pos = s.find(cercata, pos)) >= 0){
        conta_occorrenze++;
        std::cout << "L'occorrenza n." << conta_occorrenze << " di \"" << cercata <<
            "\" si trova in posizione " << pos << std::endl;
        pos += cercata.size();
    }
    std::cout << conta_occorrenze << std::endl;

    //Esempio di utilizzo di substr
    std::string sottostringa;

    sottostringa = s.substr(5);
    std::cout << sottostringa << std::endl;
    sottostringa = s.substr(5, 5);
    std::cout << sottostringa << std::endl;
    s = s.substr(4, s.size() - 5) + " a casa sua.";
    std::cout << s << std::endl;

    //Esempi di utilizzo di insert, erase e replace
    std::string nome = "Pino";
    cercata = "nonno";
    s.insert(s.find(cercata) + cercata.size()," " + nome);
    std::cout << s << std::endl;
    s.erase(s.find(nome), nome.size() + 1);
    std::cout << s << std::endl;
    s.replace(s.find(cercata) - 1, cercata.size() + 1,"la nonna");
    std::cout << s << std::endl;

    return 0;
}
