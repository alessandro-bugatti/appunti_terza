#include <iostream>
#include <fstream>

using namespace std;

/**
 * Legge un file di testo e memorizza ogni riga del file all'interno di una stringa del vettore
 * s
 * @param nomefile Nome del file da leggere, si deve trovare nella cartella cmake-build-debug
 * @param s Vettore di stringhe dove verranno copiate le righe del file
 * @return IL numero di righe lette, in caso di errore (file non presente o impossibile da aprire)
 * ritorna -1
 */
int leggi_stringhe(const string& nomefile, string s[])
{
    ifstream in(nomefile);
    if (in.fail())
        return -1;
    int contatore = 0;
    string temp;
    while(getline(in, temp)){
        s[contatore] = temp;
        contatore++;
    }
    return contatore;
}

/**
 * Scrive in un file di testo ognuna delle n stringhe contenuta nel vettore s, una per riga
 * @param nomefile
 * @param s Vettore di stringhe che verranno scritte nel file
 * @param n Numero di stringhe contenute nel vettore che dovranno essere scritte nel file
 * @return 1 nel caso tutto abbia funzionato correttamente, -1 nel caso non sia possibile
 * creare il file. Se il file esiste già viene sovrascritto, la cartella di lavoro
 * è sempre cmake-build-debug come le la lettura
 */
int scrivi_stringhe(const string& nomefile, string s[], int n)
{
    ofstream in(nomefile);
    if (in.fail())
        return -1;
    int contatore = 0;
    string temp;
    for (int i = 0; i < n; ++i) {
            in << s[i] << endl;
    }
    return 1 ;
}

int main() {
    const int MAX = 100;
    string s[MAX];
    int n = leggi_stringhe("input.txt", s);
    for (int i = 0; i < n; ++i) {
        cout << s[i] << endl;
    }
    scrivi_stringhe("output.txt",s, n);
    return 0;
}
