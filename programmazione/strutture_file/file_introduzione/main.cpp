#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/**
 * Funzione che scompone la stringa nei tre campi
 * nome, cognome e numero di telefono e li stampa a video
 * @param csv la stringa nel formato nome;cognome;telefono
 */
void stampa_campi(string csv) {
    int pos = csv.find(';');
    string nome = csv.substr(0, pos);
    int pos2 = csv.find(';', pos + 1);
    string cognome = csv.substr(pos + 1, pos2 - pos - 1);
    string telefono = csv.substr(pos2 + 1);
    cout << "Nome: " << nome << endl;
    cout << "Cognome: " << cognome << endl;
    cout << "Telefono: " << telefono << endl;
}

int main() {
    //Esempio con input numerico
    //Con questa istruzione si associa un file di input, in questo caso input.txt
    //all'oggetto, una variabile di nome in, che verrà successivamente
    //utilizzata per tutte operazioni di input sul file
    ifstream in("input.txt");
    //Controllo se l'apertura del file non è riuscita e, in questo caso,
    //si termina il programma, ma si potrebbe anche decidere di fare altro
    if (!in)
    {
        cout << "Errore nell'apertura del file" << endl;
        return 1;
    }
    //Metodo di lettura per dati numerici, tipicamente c'è un primo numero N
    //che indica quanti sono i dati e poi seguono gli N dati
    //Ovviamente il file deve essere fatto in questo modo, altrimenti la lettura
    //può fallire
    int n;
    in >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        in >> temp;
        cout << i + 1 << " -> " << temp << endl;
    }
    //Esempio con input di linee generiche
    //Con questa istruzione si associa un file di input, in questo caso input.txt
    //all'oggetto, una variabile di nome in, che verrà successivamente
    //utilizzata per tutte operazioni di input sul file
    ifstream in2("input2.txt");
    //Controllo se l'apertura del file non è riuscita e, in questo caso,
    //si termina il programma, ma si potrebbe anche decidere di fare altro
    if (!in2)
    {
        cout << "Errore nell'apertura del file" << endl;
        return 1;
    }
    //Metodo di lettura per dati generici, si leggono tutte le linee
    //fino a quando ce ne sono, poi eventualmente per ogni linea si decide
    //cosa farsene (stamparla, scomporla nei pezzi da cui è formata, ecc.)
    string s;
    while(getline(in2,s))
        cout << s << endl;
    //Esempio con input di linee in formato CSV, con il ; come separatore
    //Con questa istruzione si associa un file di input, in questo caso input.txt
    //all'oggetto, una variabile di nome in, che verrà successivamente
    //utilizzata per tutte operazioni di input sul file
    ifstream in3("input3.txt");
    //Controllo se l'apertura del file non è riuscita e, in questo caso,
    //si termina il programma, ma si potrebbe anche decidere di fare altro
    if (!in3)
    {
        cout << "Errore nell'apertura del file" << endl;
        return 1;
    }
    //Metodo di lettura per linee CSV, separate da ;
    //Si suppone che ogni linea sia composta da nome;cognome;telefono
    string csv;
    while(getline(in3,csv)){
        cout << csv << endl;
        stampa_campi(csv);
    }

    //Esempio con output, valgono le stesse considerazioni generali fatte per l'input
    ofstream out("output.txt");
    //Controlla se l'apertura avviene: un file in scrittura non viene creato
    //solo il situazioni particolari, ad esempio se non si hanno i permessi di
    //accesso alla locazione dove lo si sta creando. Se esiste già viene
    //sovrascritto
    if (!out)
    {
        cout << "Errore nell'apertura del file" << endl;
        return 1;
    }
    //Esempio che stampa la tavola pitogorica
    //out si comporta esattamente come il cout, solo che la stampa
    //avviene su file anziché a schermo
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            out << setw(5) << i * j  << " ";
        }
        out << endl;
    }
    return 0;
}
