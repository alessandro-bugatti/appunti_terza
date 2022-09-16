#include <iostream>
#include <fstream>

using namespace std;

/**
 * Serve per calcolare la media dei ricoveri per ogni mese,
 * fatta su tutti gli anni della pandemia
 */
struct RicoveriMensili{
    int totale;
    int giorni;
};

int main() {
    RicoveriMensili ricoveri_mensili[12];
    for (int i = 0; i < 12; ++i) {
        ricoveri_mensili[i].giorni = 0;
        ricoveri_mensili[i].totale = 0;
    }
    ifstream in("input.csv");
    if (!in)
    {
        cout << "Apertura fallita" << endl;
        return 1;
    }
    string riga;
    int numero_riga = 1;
    //Legge l'intestazione dei campi, solo per procedere poi con la
    //lettura dei dati
    getline(in,riga);
    //Legge tutte le linee del file
    while(getline(in,riga))
    {
        string data;
        //Estraggo la data
        int pos = riga.find(',');
        data = riga.substr(0, pos);
        cout << "Data: " << data.substr(0, 10) << " ";
        riga.erase(0, pos+1);
        //Elimino la nazione
        pos = riga.find(',');
        riga.erase(0, pos+1);
        //Recupero i ricoverati con sintomi
        string ricoverati_stringa;
        pos = riga.find(',');
        ricoverati_stringa = riga.substr(0, pos);
        cout << "Ricoverati: " << ricoverati_stringa << " ";
        riga.erase(0, pos+1);
        //Parte per memorizzare i ricoverati per ogni mese, viene estratto
        //il mese dalla data, indipendentemente dall'anno, e i ricoverati di ogni
        //giorno vengono sommati al mese corretto
        string solo_mese = data.substr(5, 2);
        int mese = stoi(solo_mese);
        int ricoverati = stoi(ricoverati_stringa);
        ricoveri_mensili[mese - 1].totale += ricoverati;
        ricoveri_mensili[mese - 1].giorni++;
        //Recupero i malati di terapia intensiva
        //Recupero i ricoverati con sintomi
        string intensiva_stringa;
        pos = riga.find(',');
        intensiva_stringa = riga.substr(0, pos);
        cout << "Intensiva: " << intensiva_stringa << endl;
        riga.erase(0, pos+1);
        numero_riga++;
    }
    in.close();
    //Stampa dei mesi con i ricoveri medi mensili
    for (int i = 0; i < 12; ++i) {
        cout << "Mese: " << i + 1 << " media ricoveri = " <<
            (float)ricoveri_mensili[i].totale / ricoveri_mensili[i].giorni << endl;
    }
    return 0;
}
