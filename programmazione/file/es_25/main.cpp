#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("testo.txt");
    string cercata, parola, riga;
    int contatore = 0;
    if (!in)
        return 1;
    cout << "Inserisci la parola da cercare: ";
    cin >> cercata;
    /*
    while(in >> parola)
        if (parola == cercata)
            contatore++;
    */
    while(getline(in, riga))
    {
        int pos = 0;
        pos = riga.find(cercata, pos);
        while ( pos != string::npos)
        {

            contatore++;
            pos = riga.find(cercata, pos + cercata.size());
        }

        cout << riga << endl;
    }


    cout << "La parola " << cercata << " compare " <<
        contatore << " volte." << endl;
    return 0;
}
