#include <iostream>

using namespace std;

struct Acquirente{
    string nome;
    string cognome;
};

struct Auto{
    string marca;
    int cilindrata;
    int immatricolazione;
    Acquirente acquirente;
};

void stampa_auto(Auto a)
{
    cout << a.marca << " " << a.acquirente.cognome << endl;
}

void stampa_autosalone(Auto macchine[], int vendute) {
    for (int i = 0; i < vendute; ++i) {
        stampa_auto(macchine[i]);
    }
}

void menu()
{
    cout << "1) Inserisci una nuova auto" << endl;
    cout << "2) Visualizza proprietari macchine cc > 1500" << endl;
    cout << "3) Immatricolate in un anno specifico" << endl;
    cout << "4) Mostra tutte le macchine" << endl;
    cout << "0) Esci" << endl;
}

void inserimento_automobile(Auto &a)
{
    cout << "Inserisci la marca: ";
    cin >> a.marca;
    cout << "Inserisci la cilindrata: ";
    cin >> a.cilindrata;
    cout << "Inserisci l'anno di immatricolazione: ";
    cin >> a.immatricolazione;
    cout << "Inserisci il nome dell'acquirente: ";
    cin >> a.acquirente.nome;
    cout << "Inserisci il cognome dell'acquirente: ";
    cin >> a.acquirente.cognome;
}

/*
 * Questa funzione serve solamente a caricare
 * 3 macchine di esempio all'avvio del programma,
 * per evitare tutte le volte di dover inserire a mano
 * i dati, in un programma vero verrebbe sostituita dal
 * caricamento di dati da un file esterno.
 */
int inizializza_esempi(Auto v[])
{
    v[0] = {
            "Fiat",
            1600,
            2020,
            {
                "Gianni",
                "Morandi"
            }
    };
    v[1] = {
            "Audi",
            2000,
            2020,
            {
                    "Fiorella",
                    "Mannoia"
            }
    };
    v[2] = {
            "Dacia",
            1400,
            2021,
            {
                    "Gino",
                    "Paoli"
            }
    };
    return 3;
}

void visualizza_macchine_cc_maggiore(Auto macchine[], int vendute)
{
    const int CC_SCELTO = 1500;
    for (int i = 0; i < vendute; ++i) {
        if(macchine[i].cilindrata > CC_SCELTO)
            stampa_auto(macchine[i]);
    }
}

void visualizza_macchine_anno(Auto macchine[], int vendute, int anno)
{
    for (int i = 0; i < vendute; ++i) {
        if(macchine[i].immatricolazione == anno)
            stampa_auto(macchine[i]);
    }
}

int main() {
    const int MACCHINE = 10;
    Auto autosalone[MACCHINE];
    int macchine_vendute = inizializza_esempi(autosalone);
    //Esempio di sintassi di come caricare tutti i dati in una
    //struttura in un "colpo solo"
    Auto esempio = {
            "Ferrari",
            2500,
            2011,
            {
                "Elena",
                "Tosti"
            }
    };
    //Esempio di sintassi di come caricare tutti i dati in una
    //struttura campo per campo
    Auto esempio2;
    esempio2.marca = "Porsche";
    esempio2.cilindrata = 3000;
    esempio2.immatricolazione = 2014;
    esempio2.acquirente.nome = "Anna";
    esempio2.acquirente.cognome = "Bislenghi";

    //Qui inizia il programma vero e proprio
    int scelta;
    menu();
    cout << "Inserisci la scelta: ";
    cin >> scelta;
    while(scelta != 0)
    {
        switch (scelta) {
            case 1:
                inserimento_automobile(autosalone[macchine_vendute]);
                macchine_vendute++;
                break;
            case 2:
                visualizza_macchine_cc_maggiore(autosalone, macchine_vendute);
                break;
            case 3:
                int anno;
                cout << "Inserisci l'anno: ";
                cin >> anno;
                visualizza_macchine_anno(autosalone, macchine_vendute, anno);
                break;
            case 4:
                stampa_autosalone(autosalone, macchine_vendute);
                break;
            default:
                cout << "Hai inserito un'opzione non valida" << endl;
        }
        menu();
        cout << "Inserisci la scelta: ";
        cin >> scelta;
    }
    return 0;
}


