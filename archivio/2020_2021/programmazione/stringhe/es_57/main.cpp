#include <iostream>

using namespace std;

int conta_parole(string frase)
{
    return 3;
}

int main()
{
    string frase;
    cout << "Inserisci una frase:" << endl;
    getline(cin, frase);
    cout << frase;
    cout << "La frase contiene " << conta_parole(frase)
        << " parole" << endl;
    return 0;
}
