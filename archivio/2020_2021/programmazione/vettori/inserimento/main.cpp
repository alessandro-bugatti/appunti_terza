#include <iostream>

using namespace std;

int main()
{
    //Dichiaro la dimensione del vettore come una
    //variabile costante
    const int N = 20;
    //Dichiaramo un vettore che può contenere fino
    //a N elementi
    int v[N];
    //Se non si usa tutto il vettore
    //c'è una variabile che dice quanti sono gli elementi validi
    int quanti = 10;
    for (int i = 0; i < quanti; i++)
        v[i] = rand()%101;
    //Quando si utilizza un vettore senza usare tutti gli elementi
    //quelli utilizzati sono generalmente i primi k elementi
    for (int i = 0; i < quanti; i++)
        cout << v[i] << endl;
    //Inseriamo un nuovo elemento in posizione p
    int p, numero;
    cout << "Inserisci la posizione: ";
    cin >> p;
    cout << "Inserisci il valore: ";
    cin >> numero;
    //Creiamo un "buco" per poter inserire il nuovo valore
    for (int i = quanti; i > p; i++)
        v[i] = v[i-1];
    //Sbagliato
    //for (int i = p + 1; i <= quanti; i++)
    //    v[i] = v[i-1];


    //Inseriamo il nuovo valore
    v[p] = numero;
    quanti++;
    cout << "Dopo l'inserimento" << endl;
    //Stampiamo per verificare la correttezza
    for (int i = 0; i < quanti; i++)
        cout << "v[" << i << "]= " << v[i] << endl;
    return 0;
}
