#include <iostream>
#include <string>
using namespace std;

int main() {
    string frase, parola;
    cout << "inserisci una frase: ";
    getline(cin, frase);
    cout << "inserisci una parola: ";
    getline(cin, parola);

    if (frase.find(parola) == string::npos)
        cout << "parola assente" << endl;
    else
        cout << "parola trovata in posizione " << frase.find(parola) << endl;


    return 0;
}