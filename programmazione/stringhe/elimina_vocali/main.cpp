#include <iostream>

using namespace std;

bool vocale(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' ||
        c == 'o' ||c == 'u' )
            return true;
    return false;
}

//Ritorna vero se c è una consonante, falso altrimenti
bool consonante(char c)
{
    /*
    if (vocale(c) == true)
        return false;
    return true;
    */
    return !vocale(c);
}

string elimina_vocali(string s)
{
    //Se la stringa fosse "buongiorno" il risultato
    //dovrebbe esser "bngrn"
    string risultato;

    for (int i = 0; i < s.size(); i++)
        //if (!vocale(s.at(i)))
        if (consonante(s.at(i)))
            risultato += s.at(i);
    return risultato;
}

int main()
{
    string s;
    cout << "Inserisci una parola: ";
    cin >> s;
    cout << "La parola senza vocali risulta " <<
        elimina_vocali(s) << endl;
    return 0;
}
