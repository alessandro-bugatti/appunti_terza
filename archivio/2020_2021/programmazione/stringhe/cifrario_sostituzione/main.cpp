#include <iostream>

using namespace std;

char conversione(char c, string chiave)
{
    return chiave.at(c - 'a');
}


string converti(string chiaro, string chiave)
{
    string risultato;
    for (int i = 0; i < chiaro.size(); i++)
        risultato += conversione(chiaro.at(i), chiave);
    return risultato;
}

string decodifica(string cifrato, string chiave)
{
    string risultato;
    for (int i = 0; i < cifrato.size(); i++)
        risultato += chiave.find(cifrato.at(i)) + 'a';
    return risultato;
}


int main()
{
    string chiave = "pasdfghjklwqertyuiozxcvbnm";
    //cout << "Inserisci la chiave di cifratura:";
    //cin >> chiave;

    /*
    Idea di partenza
    'a' -> 'r'
    'b' -> 'g'
    'c' -> 'h'
    'd' -> 'a'
    ecc.*/
    /*
    Implementazione scorretta
    if (s.at(i) == 'a')
        s.at(i) = 'r';
    ecc. ecc.*/
    string chiaro = "buongiorno";
    string cifrato = converti(chiaro, chiave);
    string decodificato = decodifica(cifrato, chiave);
    cout << "La stringa in chiaro era " << chiaro << endl;
    cout << "La stringa codificata diventa " << cifrato << endl;
    cout << "La stringa decodificata diventa " << decodificato << endl;

    return 0;
}
