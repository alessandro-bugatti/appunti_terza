#include <iostream>

using namespace std;

string cambio_in_minuscolo(string s)
{
    for (int i = 0; i < s.size(); i++)
        if (s.at(i) == ' ')
            s.at(i) = '_';
        else
            s.at(i) = s.at(i) - 'A' + 'a';
        //risultato += s.at(i) + 32; //32 perchè è la distanza in ASCII tra
                                    //maiuscole e minuscole
    return s;
}


string crea_email(string csv)
{
    string risultato;
    int inizio = 0, fine = csv.find(";");
    string cognome = csv.substr(inizio, fine - inizio);
    risultato = cambio_in_minuscolo(cognome);
    inizio = fine + 1;
    fine = csv.find(";",inizio);
    string nome = csv.substr(inizio, fine - inizio);
    risultato += "." + cambio_in_minuscolo(nome);
    return risultato;
}

int main()
{
    //Ridirezione dell'input
    freopen("elenco_con_date.csv", "r", stdin);
    freopen("elenco_email.txt", "w", stdout);
    string s;
    //finchè la getline riesce a leggere una stringa
    while (getline(cin, s))
        cout << crea_email(s) << endl;

    //Output: ALBERTO.ARRIVETTI@itiscastelli.it
    //cout << crea_email(csv);
    return 0;
}
