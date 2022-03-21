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



string codifica_uno(string chiaro)
{
    string codificata;
    for (int i = 0; i < chiaro.size(); ++i) {
        char c = chiaro.at(i);
        if (c == 'z')
            codificata += 'a';
        else if (c == 'Z')
            codificata += 'A';
        //Se è una lettera minuscola o maiuscola
        else if ((c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z'))
            codificata += (c + 1);
        else
            codificata += c;
    }
    return codificata;
}

string codifica_cesare(string chiaro, int n)
{
    string codificata;
    for (int i = 0; i < chiaro.size(); ++i) {
        char c = chiaro.at(i);
        if ((c >= 'a' && c <= 'z') )
            codificata += (((c + n) - 'a') % 26) + 'a';
        else if(c >= 'A' && c <= 'Z')
            codificata += (((c + n) - 'A') % 26) + 'A';
        else
            codificata += c;
    }
    return codificata;
}


string codifica_sostituzione(string chiaro, string chiave)
{
    string codificata;
    string chiaveMaiuscola;
    for (int i = 0; i < chiave.size(); ++i) {
        chiaveMaiuscola += toupper(chiave.at(i));
    }
    for (int i = 0; i < chiaro.size(); ++i) {
        char c = chiaro.at(i);
        if ((c >= 'a' && c <= 'z') )
            codificata += chiave.at(chiaro.at(i) - 'a');
        else if(c >= 'A' && c <= 'Z')
            codificata += chiaveMaiuscola.at(chiaro.at(i) - 'A');
        else
            codificata += c;
    }
    return codificata;
}


int main() {
    const int N_STRINGHE = 100;
    string v[N_STRINGHE];
    string chiave = "qwertyuioplkjhgfdsazxcvbnm";
    int n_righe = leggi_stringhe("chiaro.txt", v);
    for (int i = 0; i < n_righe; ++i) {
        //v[i] = codifica_cesare(v[i], 8);
        v[i] = codifica_sostituzione(v[i], chiave);
    }
    scrivi_stringhe("cifrato.txt", v, n_righe);
//    char c = 'a';
//    c = (((c + 7) - 'a') % 26) + 'a';
//    cout << c << endl;
    return 0;
}
