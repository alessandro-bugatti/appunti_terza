#include <iostream>

using namespace std;

string crea_email(string csv)
{
    string nome, cognome;
    //Algoritmo di estrazione delle informazioni
    //Utilizzo di find per trovare ;
    int separatore = csv.find(";");

    //Utilizzo substr per estrarre il nome e il cognome
    cognome = csv.substr(0, separatore);
    nome = csv.substr(separatore + 1);
    return nome + "." + cognome + "@itiscastelli.it";
}

int main()
{
    //Ridirezione dell'input
    freopen("elenco.csv", "r", stdin);
    freopen("elenco_email.txt", "w", stdout);
    string s;
    //finchè la getline riesce a leggere una stringa
    while (getline(cin, s))
        cout << crea_email(s) << endl;

    //Output: ALBERTO.ARRIVETTI@itiscastelli.it
    //cout << crea_email(csv);
    return 0;
}
