#include <iostream>

using namespace std;

//Alessandro Bugatti

int main()
{
    //int per variabili intere
    //float per variabili con virgola
    float costo, costo_scontato;
    //float costo_scontato;

    //Output usando la cout (pensatelo come lo schermo)
    cout << "Inserisci un numero: ";

    //Input usando la cin (pensatelo come la tastiera)
    cin >> costo;

    costo_scontato = costo * 0.7;

    //cout << endl << endl << endl;
    cout << "Dopo lo sconto dovrai pagare " <<
        costo_scontato << " euro.";// << endl;

    return 0;
}
