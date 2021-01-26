#include <iostream>
#include <ctime>

using namespace std;

//Quando si passa un vettore si indicano le quadre
//ma non si inserisce nessun valore
stampa_vettore(int v[], int n)
{
    for (int i=0; i < n; i++)
        cout << "posizione " << i << " => " << v[i] << endl;
}

int main()
{
    //srand(time(NULL));
    const int DIMENSIONE = 20;
    int vettore[DIMENSIONE];
    int quanti = DIMENSIONE;
    for (int i=0; i < quanti; i++)
            vettore[i] = rand()%101;

    cout << "vettore:" << endl;
    stampa_vettore(vettore, quanti);


    int posizione;

    do{
        cout << endl << "in che posizione vuoi eliminare il valore? => ";
        cin >> posizione;
    }while (posizione>quanti);

    for (int i=posizione; i<quanti; i++)
        vettore[i]=vettore[i+1];

    quanti--;

    cout << "vettore:" << endl;
    stampa_vettore(vettore, quanti);

    return 0;
}
