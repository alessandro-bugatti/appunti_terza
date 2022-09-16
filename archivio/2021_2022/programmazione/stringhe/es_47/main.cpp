#include <iostream>

using namespace std;

bool vocale(char c){
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o'
        || c == 'u')
        return true;
    return false;
}

/**
 *
 * @param s La stringa di cui si vogliono contare le vocali o le consonanti
 * @param c Un carattere che dice se si vogliono contare le vocali (V) oppure
 * le consonanti (C)
 * @return Il numero di vocali o consonanti
 */
int contaLettere(string s, char c)
{
    int contatore = 0;
    for (int i = 0; i < s.size(); ++i) {
        char lettera_attuale = s.at(i);
        if (c == 'V' && vocale(lettera_attuale))
            contatore++;
        if (c == 'C' && !vocale(lettera_attuale))
            contatore++;
    }
    return contatore;
}

int main() {
    //Primo modo di testare, scrivo nel codice gli esempi
    cout << contaLettere("abete", 'V') << endl;
    cout << contaLettere("aBete", 'C') << endl;
    //Secondo modo, con l'interazione dell'utente
    cout << "Inserisci una parola: " << endl;
    string parola;
    cin >> parola;
    cout << "Inserisci se vuoi contare le vocali (V) o le consonanti (C): ";
    char scelta;
    cin >> scelta;
    cout << "Risultato: " << contaLettere(parola, scelta) << endl;
    return 0;
}
