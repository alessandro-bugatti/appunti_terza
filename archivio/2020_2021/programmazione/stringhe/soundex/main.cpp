#include <iostream>

using namespace std;

string rimuovi(string s)
{

}

string sostituisci(string s)
{

}

string rimuovi_doppi(string s)
{

}

string finalizza(string s)
{

}

int main()
{
    string originale, soundex;
    cout << "Inserisci la stringa su cui fare il SOUNDEX: ";
    cin >> originale;
    //Mantengo la prima lettera
    soundex += originale.at(0);
    string senza_prima = originale.substr(1);
    //rimuovo le lettere a e h i o u w y
    string rimosse = rimuovi(senza_prima);
    //Trasformo le lettere rimaste in cifre seconde le regole indicate
    soundex += sostituisci(rimosse);
    //Si rimuovono eventuali duplicati
    soundex = rimuovi_doppi(soundex);
    //La si riduce nella forma finale con 4 caratteri
    soundex = finalizza(soundex);
    return 0;
}
