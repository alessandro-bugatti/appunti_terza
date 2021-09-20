#include <iostream>

using namespace std;

//Codice di Cesare "generalizzato"
//La chiave rappresenta il numero di posizioni
//di cui bisogna spostarsi in avanti per la codifica
string codifica(string testo, int chiave)
{
    string risultato;
    for (int i = 0; i < testo.size(); i++)
    {
        if (testo.at(i) + chiave > 'z')
            risultato += (testo.at(i) + chiave - 26);
        else
            risultato += (testo.at(i) + chiave);
    }
    return risultato;
}

int main()
{
    cout << codifica("ciao", 2) << endl;

    return 0;
}
