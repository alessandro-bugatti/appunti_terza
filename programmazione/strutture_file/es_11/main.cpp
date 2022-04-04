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

void menu()
{
    cout << "1) Inserisci una nuova auto" << endl;
    cout << "2) Visualizza proprietari macchine cc > 1500" << endl;
    cout << "3) Immatricolate in un anno specifico" << endl;
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

int main() {
    const int MACCHINE = 10;
    Auto autosalone[MACCHINE];
    int macchine_vendute = inizializza_esempi(autosalone);
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
                break;
            case 3:
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
