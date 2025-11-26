#include <iostream>

int conta(int n, int cifra) {
    int contatore = 0;
    while (n > 0) {
        if (n % 10 == cifra) {
            contatore++;
        }
        n /= 10;
    }
    return contatore;
}

/**
 * Serve a contare quante volte una certa cifra compare nell'intervallo di numeri che partono da n1 e arrivano a n2.
 * Se n1 e n2 non sono nell'ordine corretto, la funzione li scambia
 * @param n1 Inizio dell'intervallo compreso
 * @param n2 Fine dell'intervallo compreso
 * @param cifra La cifra da contare
 * @return Numero di volte che cifra si trova nell'intervallo
 */
int conta_cifre(int n1, int n2, int cifra) {
    //Scambia eventualmente gli estremi dell'intervallo
    if (n1 > n2) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    //COnta le volte in cui compare cifra
    int contatore = 0;
    for (int i = n1; i <= n2; ++i) {
        contatore += conta(i, cifra);
    }
    return contatore;
}

int main() {
    std::cout << conta_cifre(8, 133, 7) << std::endl;
    return 0;
}