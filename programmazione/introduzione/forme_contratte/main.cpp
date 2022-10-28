#include <iostream>

int main() {
    int n = 5, contatore = 0, somma = 0;
    for (int i = 0; //inizializzazione
            i < n; //condizione che se è vera il corpo viene svolto, altrimenti si esce dal for
            ++i) //incremento, viene fatto prima di iniziare un nuovo giro
    {
        contatore++; //equivale a contatore = contatore + 1 oppure contatore += 1
        somma += 6; //Equivale a somma = somma + 6
        //Per le forme contratte si puà usare un qualsiasi operatore
        // += -= *= /=
    }
    //Versione equivalente del for qua sopra con while
    int i = 0;
    while(i < n){
        //istruzioni
        ++i;
    }
    return 0;
}
