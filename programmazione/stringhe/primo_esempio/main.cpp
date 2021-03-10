#include <iostream>

using namespace std;

int v[100000000];

int main()
{
    //Dichiarazione di stringa stile C
    char s[10];

    //Esempio artificiale
    s[0] = 'm';
    s[1] = 'i';
    s[2] = 'a';
    s[3] = 'o';

    v[0] = 5555;
    v[1] = 11;

    //Questa funzione come atteso
    cout << "Stringa: " << s << endl;
    //Questa invece stampa un indirizzo
    cout << "Vettore: " << v << endl;

    //Input di stringa stile C
    cout << "Inserisci una parola: ";
    cin >> s;
    cout << "Parola inserita: ";
    cout << s << endl;

    //Stampa di tutti i caratteri di una stringa,
    //anche quelli eventualmente non assegnati dall'input
    //fatto in precedenza
    for (int i = 0; i < 10; i++)
        cout << (int)s[i] << " -> " << s[i] << endl;
    cout << endl;
    return 0;
}
