#include <iostream>
#include <sstream>
#include <vector>

struct Data{
    int giorno;
    int mese;
    int anno;
};

struct Valutazione {
    float voto;
    std::string materia;
    Data data;
};

struct Studente {
    std::string nome;
    std::string cognome;
    Data nascita;
    int classe;
    char sezione;
    std::vector <Valutazione> valutazioni;
};

std::vector<std::string> split(const std::string& s, char delimiter = ' ')
{
    std::stringstream in(s);
    std::string temp;
    std::vector<std::string> v;
    while(getline(in, temp, delimiter))
        v.push_back(temp);
    return v;
}


int main()
{

    return 0;
}
