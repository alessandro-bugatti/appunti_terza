#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int somma = 0;
    //Ci sono tre parti separate da ;
    //La prima parte è l'inizializzazione e viene fatta subito
    //La seconda parte è una condizione, se vera il ciclo entra, se falsa esce
    //Viene testata appena fatta l'inizializzazione, come il while
    //L'ultima parte in generale aggiorna la variabile di ciclo
    for (int i = 0; i <= n; i++/*i = i  + 1*/) {
        somma += i; //somma = somma + i;
    }
    cout << somma << endl;
    return 0;
}
