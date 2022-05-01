#include <iostream>
#include <fstream>

using namespace std;

/**
 * Ricerca il numero di volte che una parola si trova all'interno
 * di frase. La ricerca trova la parola anche se non è parte di un'altra parola
 * Esempio: se parola = "re" e frase = "regolare" viene ritornato 2
 * @param frase La frase dentro cui cercare una parola
 * @param parola La parola da cercare
 * @return Numero di volte che parola viene trovata dentro frase
 */
int trova_parola(const string& frase, const string& parola)
{
    int pos = 0;
    int cont = 0;
    pos = frase.find(parola, pos);
    while ( pos >= 0){
        cont++;
        pos = frase.find(parola, pos + 1);
    }
    return cont;
}

int main() {
    ifstream in("testo.txt");
    if (!in){
        cout << "Errore in apertura" << endl;
        return 1;
    }
    string riga;
    string parola;
    cout << "Inserisci una parola" << endl;
    getline(cin, parola);
    int conta_occorrenze = 0;
    while(getline(in, riga)){
        conta_occorrenze += trova_parola(riga, parola);
    }
    cout << "Nel file la parola " << parola << " si trova " <<
    conta_occorrenze << " volte"<< endl;
    return 0;
}
