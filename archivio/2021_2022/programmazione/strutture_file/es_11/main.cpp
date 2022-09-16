#include <iostream>
#include <fstream>

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

/**
 * Funzione che prende una riga estratta dal file dove sono memorizzate
 * le macchine, la scompone nei suoi campi e restituisce la struttura
 * composta con quei valori
 * @param riga Stringa CSV contenente i dati di un'auto
 * @return La struttura Automobile riempita con tutti i dati
 */
Auto elabora_auto(string riga){
    Auto macchina;
    //Estrae la marca, che si trova prima del primo punto e virgola
    int pos = riga.find(';');
    macchina.marca = riga.substr(0,pos);
    //Estrae la cilindrata e la trasforma in un intero
    int pos_prec = pos;
    pos = riga.find(';',pos_prec + 1);
    string temp;
    temp = riga.substr(pos_prec + 1, pos - pos_prec - 1);
    macchina.cilindrata = stoi(temp);
    //Estrae l'anno di immatricolazione e lo trasforma in un intero
    pos_prec = pos;
    pos = riga.find(';',pos_prec + 1);
    temp = riga.substr(pos_prec + 1, pos - pos_prec - 1);
    macchina.immatricolazione = stoi(temp);
    //Estrae il nome dell'acquirente
    pos_prec = pos;
    pos = riga.find(';',pos_prec + 1);
    macchina.acquirente.nome = riga.substr(pos_prec + 1, pos - pos_prec - 1);
    //Estrae il cognome dell'acquirente, dall'ultimo punto e virgola fino alla fine
    macchina.acquirente.cognome = riga.substr(pos + 1);
    return macchina;
}

//Tracciato del file
//marca;cilindrata;immatricolazione;nome;cognome
/**
 * Funzione per caricare le macchine dal file
 * @param automobili Vettore dove verranno inserite le macchine
 * @param filename Nome del file delle macchine
 * @return Numero di macchine caricate, -1 se l'apertura non va a buon fine
 */
int carica_file(Auto automobili[], string filename)
{
    ifstream in(filename);
    if (!in)
        return -1;
    string temp;
    int contatore = 0;
    while(getline(in, temp)){
        Auto macchina = elabora_auto(temp);
        automobili[contatore] = macchina;
        contatore++;
    }
    in.close();
    return contatore;
}

/**
 * Funzione che salva il vettore delle macchine su file
 * @param automobili Vettore delle macchine
 * @param n_auto Numero di macchine presenti nel vettore
 * @param filename File dove salvare le macchine
 * @return 0 successo, -1 problemi nell'apertura
 */
int salva_file(Auto automobili[], int n_auto, string filename )
{
    ofstream out(filename);
    if (!out)
        return -1;
    for (int i = 0; i < n_auto; ++i) {
        out << automobili[i].marca << ";"
        << automobili[i].cilindrata << ";"
        << automobili[i].immatricolazione << ";"
        << automobili[i].acquirente.nome << ";"
        << automobili[i].acquirente.cognome << endl;
    }
    out.close();
    return 0;
}

void stampa_auto(Auto a)
{
    cout << a.marca << " "<< a.cilindrata
    << " " << a.immatricolazione << " "
    << a.acquirente.nome << " "
    << a.acquirente.cognome << endl;
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
    const int MACCHINE = 1000;
    Auto autosalone[MACCHINE];
    int macchine_vendute = 0;// = inizializza_esempi(autosalone);
    //Esempio di sintassi di come caricare tutti i dati in una
    //struttura in un "colpo solo"
    /*Auto esempio = {
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
    */
    macchine_vendute = carica_file(autosalone, "automobili.txt");
    if (macchine_vendute == -1) {
        cout << "Non è stato trovato il file delle automobili" << endl;
        macchine_vendute = 0;
    }
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
    salva_file(autosalone, macchine_vendute, "automobili.txt");
    return 0;
}


