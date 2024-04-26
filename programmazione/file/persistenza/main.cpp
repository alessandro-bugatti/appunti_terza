#include <iostream>
#include <fstream>
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

std::vector<Studente> carica(const std::string &nome_file) {
    std::ifstream in(nome_file);
    std::vector<Studente> v;
    if (!in) return v;
    std::string temp;
    std::getline(in,temp);
    int n_studenti = std::stoi(temp);
    for (int i = 0; i < n_studenti; i++) {
        Studente s;
        std::getline(in, temp);
        std::vector<std::string> tokens ;
        tokens = split(temp,';');
        s.nome = tokens.at(0);
        s.cognome = tokens.at(1);
        s.nascita.giorno = stoi(tokens.at(2));
        s.nascita.mese = stoi(tokens.at(3));
        s.nascita.anno = stoi(tokens.at(4));
        s.classe = stoi(tokens.at(5));
        s.sezione = tokens.at(6).at(0);
        int n_valutazioni;
        n_valutazioni = stoi(tokens.at(7));
        for (int i = 0; i < n_valutazioni; i++) {
            std::getline(in, temp);
            tokens = split(temp, ';');
            Valutazione val;
            val.voto = stof(tokens.at(0));
            val.materia = tokens.at(1);
            val.data.giorno = stoi(tokens.at(2));
            val.data.mese = stoi(tokens.at(3));
            val.data.anno = stoi(tokens.at(4));
            s.valutazioni.push_back(val);
        }
        v.push_back(s);
    }
    in.close();
    return v;
}

int main()
{
    // std::vector<std::string> v;
    // v = split("Alessandro;Bugatti;Informatica",';');
    // for (int i = 0; i < v.size(); i++)
    //     std::cout << v.at(i) << std::endl;

    std::vector<Studente> studenti = carica("dati.txt");

    return 0;
}