#include <iostream>

using namespace std;

struct Data{
    int giorno;
    int mese;
    int anno;
};

struct TesseraSanitaria{
    string codice_fiscale;
    string nome;
    string cognome;
    string luogo_di_nascita;
    Data data_di_nascita;
};

void stampa_data(const Data &d)
{
    cout << d.giorno <<
        "/" << d.mese << "/" <<
        d.anno << endl;
}

void stampa(const TesseraSanitaria &t)
{
    cout << "Tessera sanitaria di "
        << t.cognome << " " << t.nome << endl;
    cout << "Codice fiscale: " << t.codice_fiscale << endl;
    cout << "Nato il ";
    stampa_data(t.data_di_nascita);
}

bool minore_di(TesseraSanitaria a, TesseraSanitaria b)
{
    if (a.codice_fiscale < b.codice_fiscale)
        return true;
    return false;
}

int main()
{
    TesseraSanitaria a, b;
    //Assegnamento dei singoli campi
    //cin >> a; //NO
    cout << "Inserisci il codice fiscale: ";
    cin >> a.codice_fiscale;
    cout << "Inserisci la data di nascita: ";
    //cin >> a.data_di_nascita;//NO
    cout << "Giorno: ";
    cin >> a.data_di_nascita.giorno;
    cout << "Mese: ";
    cin >> a.data_di_nascita.mese;
    cout << "Anno: ";
    cin >> a.data_di_nascita.anno;

    //cout << a; //NO
    stampa(a);
    TesseraSanitaria c = a + b; //NO
    if (a < b)        //NO
        fai_qualcosa; //NO
    if (a.codice_fiscale < b.codice_fiscale)
        fai_qualcosa;
    if (minore_di(a, b))
        fai_qualcosa;
    b = a; //VALIDA
    TesseraSanitaria v[10];
    v[2].codice_fiscale = "FFGJFGDJ";
    v[3].data_di_nascita.giorno = 1;
    v.codice_fiscale = "ggfjf"; //SINTASSI SBAGLIATA
    return 0;
}
