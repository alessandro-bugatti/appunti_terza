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

//Funzione per l'eliminazione di un elemento
//Prima versione con il passaggio per riferimento
//del numero di elementi
void elimina(int v[], int &n, int posizione)
{
    for (int i=posizione; i<n; i++)
        v[i]=v[i+1];
    n--;
}

//Funzione per l'eliminazione di un elemento
//Seconda versione con il ritorno
//del numero di elementi
/*int elimina(int v[], int n, int posizione)
{
    for (int i=posizione; i<n; i++)
        v[i]=v[i+1];
    n--;
    return n;
}*/


int main()
{
    //srand(time(NULL));
    const int DIMENSIONE = 10;
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

    //Come va chiamata la prima versione
    elimina(vettore, quanti, posizione);

    //Come va chiamata la seconda versione
    //quanti = elimina(vettore, quanti, posizione);

    cout << "vettore:" << endl;
    stampa_vettore(vettore, quanti);

    return 0;
}
