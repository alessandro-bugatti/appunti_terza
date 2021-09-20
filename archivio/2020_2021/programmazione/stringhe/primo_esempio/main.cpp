#include <iostream>

using namespace std;


int main()
{
    //Dichiarazione di stringa stile C
    char s[10];
    int n;

    //Esempio artificiale
    s[0] = 'm';
    s[1] = 'i';
    s[2] = 'a';
    s[3] = 'o';



    //Questa funzione come atteso
    cout << "Stringa: " << s << endl;


    //Input di stringa stile C
    cout << "Inserisci una parola: ";
    //cin >> &s[2]; //Prendi l'indirizzo della terza cella di s
    //s[2] = '\0';
    cin >> s;
    cout << "Parola inserita: ";
    cout << s << endl;


    //Stampa di tutti i caratteri di una stringa,
    //anche quelli eventualmente non assegnati dall'input
    //fatto in precedenza e anche quelli che si
    //trovano fuori dalla stringa
    for (int i = 0; i < 20; i++)
        cout << "s[" << i << "]" << (int)s[i] << " -> " << s[i] << endl;
    cout << endl;
    return 0;
}
