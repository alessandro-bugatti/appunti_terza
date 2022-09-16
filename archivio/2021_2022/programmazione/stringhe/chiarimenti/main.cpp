#include <iostream>

using namespace std;

void stampa_tagliati(string v[], int n)
{
    for (int i = 0; i < n; ++i) {
        string t = v[i];
        t.erase(0, 3);
        cout << t << endl;
    }
}

int main() {
    string frase;
    /*
    //NOn va bene se è una frase, va bene solo per parole singole
    // cin >> frase;
    getline(cin, frase);
    cout << frase << endl;
    cout << frase.size() << endl;
    //Vettori di stringhe
    const int DIM = 10;
    int n;
    string v[DIM];
    cout << "Dimmi quante frasi vuoi inserire: ";
    cin >> n;
    //Brutto modo per risolvere il problema dell'a capo che lascia
    //la cin
    getline(cin, frase);
    cout << "Inserisci le frasi" << endl;
    for (int i = 0; i < n; ++i) {
        getline(cin, v[i]);
    }
    stampa_tagliati(v, n);
     */
    frase = "ciao a tutto il mondo";
    int n = frase.find("a t");
    cout << n << endl;
    return 0;
}
