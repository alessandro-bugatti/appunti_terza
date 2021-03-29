#include <iostream>

using namespace std;

int codice_numerico(string s)
{
    int somma = 0;
    for (int i = 0; i < s.size(); i++)
        somma += s.at(i);
    return somma;
}
int main()
{
    string input, prova;
    cout << "Inserisci una parola: ";
    cin >> input;
    cout << "Il suo codice numerico è :" << codice_numerico(input) << endl;
    cout << "Cerca una parola con lo stesso codice numerico. Inserisci: ";
    cin >> prova;
    while(codice_numerico(input) != codice_numerico(prova))
    {
        cout << "Non sono uguali, il codice della tua parola vale " <<
            codice_numerico(prova) << ". Riprova: ";
        cin >> prova;
    }
    cout << "Bravo, hai vinto" << endl;



    return 0;
}
