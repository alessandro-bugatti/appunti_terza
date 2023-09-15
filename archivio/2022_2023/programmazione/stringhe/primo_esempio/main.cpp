#include <iostream>
#include <string>

//Stringhe passate sempre per riferimento per evitare la copia
//Se non le si vuole modificare si usa la parola const
std::string maiuscola_prima_lettera(const std::string &s){
    std::string modificata = s;
    modificata.at(0) = modificata.at(0) - 'a' + 'A';
    return modificata;
}
/**
 *
 * @param prima
 * @param seconda
 * @return prima_seconda
 */
std::string snake(std::string prima, std::string seconda){
    return prima + '_' + seconda;
}

/**
 *
 * @param prima
 * @param seconda
 * @return primaSeconda
 */
std::string camel(std::string prima, std::string seconda){
    return prima + maiuscola_prima_lettera(seconda);
}


int main() {
    std::string s;
    std::cout << "Inserisci una parola: ";
    //std::cin >> s;
    s = "ciao";
    std::cout << s;
    //Assegnamento
    std::string t = s;
    //Chiedere quanto è lunga una stringa con il metodo size()
    std::cout << "La stringa che hai inserito è fatta da " <<
        s.size() << " caratteri " << std::endl;
    //Accesso alle lettere da cui è composta una parola
    //Versione C
    for (int i = 0; i < s.size() + 1; ++i) {
        std::cout << "Lettera " << i + 1 << " -> " << s[i] << std::endl;
    }
    //Versione C++
    for (int i = 0; i < s.size(); ++i) {
        std::cout << "Lettera " << i + 1 << " -> " << s.at(i) << std::endl;
    }
    t = "roberto";
    std::cout << maiuscola_prima_lettera(t) << std::endl;
    //Concatenazione tra stringhe
    t = maiuscola_prima_lettera(t);
    std::string r = s + " signor " + t;
    std::cout << r << std::endl;
    std::cout << snake("eleva", "potenza") << std::endl;
    std::cout << camel("eleva", "potenza") << std::endl;
    return 0;
}
