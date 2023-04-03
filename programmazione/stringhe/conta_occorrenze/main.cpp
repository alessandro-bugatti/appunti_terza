#include <iostream>

int trovato (const std::string &frase, const std::string &s){
    int contatore = 0;
    int pos = 0;
    while((pos = frase.find(s, pos)) != std::string::npos){
        contatore++;
        pos++; //pos += s.size();
    }
    return contatore;
}

/**
 * Ritorna il numero di occorrenze della stringa s all'interno del vettore v
 * @param v Vettore di stringhe
 * @param n NUmero di stringhe presenti nel vettore
 * @param s Stringa da ricercare
 * @return Numero di volte totale in cui s compare all'interno delle stringhe contenute in v
 */

int conta_occorrenze(std::string v[], int n,const std::string &s){
    int contatore = 0;
    for (int i = 0; i < n; ++i) {
        contatore += trovato(v[i], s);
    }
    return contatore;
}

int main() {
    const int N_STRINGHE = 10;
    std::string frasi[N_STRINGHE];
    int n;
    /*
    frasi[0] = "la mia macchina è verde e va veloce";
    frasi[1] = "ieri ho pescato una verdesca";
    frasi[2] = "verde come il latte, verde come il sangue";
     */
    //Input dell'utente
    std::string temp;
    std::cout << "Inserisci il numero di frasi: ";
    std::getline(std::cin, temp);
    n = std::stoi(temp);
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, frasi[i]);
    }

    int quante = conta_occorrenze(frasi, 3, "e");
    std::cout << quante << std::endl;
    return 0;
}
