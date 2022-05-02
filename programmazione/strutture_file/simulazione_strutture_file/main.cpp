#include <iostream>
#include <fstream>

using namespace std;

//Simulazione reperibile all'indirizzo
//http://www.imparando.net/sito/introduzione_alla_programmazione_in_C/simulazioni_di_verifiche/simulazione%20strutture.pdf

//Esercizio 1
struct Docente{
    string nome;
    string cognome;
    int anno_nascita;
    string materia;
};

struct Classe{
    int anno;
    string sezione;
    int n_alunni;
    Docente tutor;
};

//Esercizio 2

struct Razionale{
    int numeratore;
    int denominatore;
};

Razionale somma(Razionale a, Razionale b)
{
    Razionale c;
    c.numeratore = a.numeratore*b.denominatore + b.numeratore*a.denominatore;
    c.denominatore = a.denominatore * b.denominatore;
    for (int i = c.numeratore; i > 1 ; --i) {
        if (c.numeratore % i == 0 &&
        c.denominatore % i == 0)
        {
            c.numeratore = c.numeratore / i;
            c.denominatore/= i;
        }
    }
    return c;
}

//Esercizio 3
struct Data{
    int g, m, a;
};

struct ContoCorrente{
    int numero_conto;
    Data data_apertura;
    float saldo;
};

float calcola_media(ContoCorrente c[], int n, int anno)
{
    float media = 0;
    int conta = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i].data_apertura.a == anno)
        {
            media += c[i].saldo;
            conta++;
        }
    }
    return media/conta;
}

//Esercizio 4
struct Carta{
    int seme;
    int valore;
};

int coppia(Carta c[], int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (c[i].valore == c[j].valore)
                return 1;
        }
    }
    return 0;
}

int stesso_seme(Carta c[], int n)
{
    int seme = c[0].seme;
    for (int i = 1; i < n; ++i) {
        if (c[i].seme != seme)
            return 0;
    }
    return 1;
}

int main() {
    const int N_CARTE = 5;
    Carta carte[N_CARTE];
    int conta_coppie = 0, conta_colore = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << "Inserisci una carta.";
            cout << "Seme (0-3):";
            cin >> carte[j].seme;
            cout << "Inserisci il valore (1-13):";
            cin >> carte[j].valore;
        }
        conta_coppie += coppia(carte, N_CARTE);
        conta_colore += stesso_seme(carte, N_CARTE);
    }
    cout << "Ci sono " << conta_coppie << " mani che contengono almeno una coppia" << endl;
    cout << "Ci sono " << conta_colore << " manio che contengono tutte carte dello stesso seme" << endl;
    return 0;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("scontrino.txt");
    if (!in || !out)
    {
        cout << "Errore nell'apertura dei file" << endl;
        return 1;
    }
    int qta, sconto;
    float costo, totale = 0;
    while(in >> qta >> costo >> sconto)
    {
        totale = qta * costo * (100 - sconto)/100.0;
    }
    out << totale << endl;
    in.close();
    out.close();
    return 0;
}
