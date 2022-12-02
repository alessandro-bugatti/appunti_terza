#include <iostream>
#include <cmath>

//Sintassi di una funzione tipo_ritorno nome_funzione(parametri)

/**
 * Calcola l'elevamento del numero due a una potenza intera con esponente positivo
 * @param n L'esponente a cui elevare 2
 * @return IL valore di 2 elevato alla n
 */
int potenza_di_due(int n) //Firma della funzione
{
    int risultato = 1;
    for (int i = 0; i < n; ++i) {
        risultato *= 2;
    }
    //Alla fine della computazione ritornano qualcosa a chi le ha usate (il chiamante)
    return risultato;
}

int main() {
    int potenza, esponente;
    std::cout << "Inserisci l'esponente intero positivo: ";
    std::cin >> esponente;
    potenza = potenza_di_due(esponente); //Chiamata di funzione
    std::cout << "2 elevato alla " << esponente << " da come risultato " << potenza;
    return 0;
}
