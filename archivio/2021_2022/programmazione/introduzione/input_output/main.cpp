//Prima parte che include le direttive al preprocessore
//In particolare questa direttiva, la include,
//include le librerie da importare
#include <iostream> //libreria per l'I/O

//Riga che aggiungeremo sempre per semplificare
//la scrittura di alcune parti
using namespace std;

//Punto dove parte il programma
//Il main contiene sempre un blocco di codice
//delimitato dalle parentesi graffe
int main() {
    //Dichiarazione delle variabili
    int a;
    float b;
    double c;
    //Input della variabile intera
    cout << "Inserisci un numero intero: ";
    cin >> a;
    cout << "Il numero che hai inserito è il "
        << a << endl << endl << endl;
    //Input della variabile float
    cout << "Inserisci un numero con virgola: ";
    cin >> b;
    cout << "Il numero che hai inserito è il "
         << b << endl;

    return 0;
}
