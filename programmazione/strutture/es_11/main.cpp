#include <iostream>

using namespace std;

struct Auto{
    string marca;
    int cilindrata;
    int anno_immatricolazione;
    string nome;
    string cognome;
};

Auto inserisci_auto()
{
    Auto a;
    cout << "Marca: ";
    cin >> a.marca;
    cout << "Cilindrata: ";
    cin >> a.cilindrata;
    return a;
}

void riepilogo(Auto v[], int n)
{
    cout << "Autovendute: " << n << endl;
    for (int i = 0; i < n; i++)
        cout << i+1 << " - " << v[i].marca << endl;
}

void menu()
{
    cout << endl << "GESTIONE AUTO" << endl << endl;
    cout << "1 - Inserisci una macchina venduta" << endl;
    cout << "2 - Visualizza il cognome dei proprietari di macchine con più di 1500 di cilindrata" << endl;
    cout << "3 - Mostra il numero totale di auto immatricolate in un certo anno" << endl;
    cout << "4 - Riepilogo" << endl;
    cout << "0 - Esci" << endl << endl;

}

int main()
{
    const int MAX_AUTO = 10;
    Auto autosalone[MAX_AUTO];
    int auto_vendute = 0;
    int scelta = 1;
    while(scelta != 0)
    {
        menu();
        cout << "Inserisci la tua scelta: ";
        cin >> scelta;
        if (scelta == 1)
        {
            Auto temp = inserisci_auto();
            autosalone[auto_vendute] = temp;
            auto_vendute++;
        }
        if (scelta == 4)
            riepilogo(autosalone, auto_vendute);


    }
    return 0;
}
