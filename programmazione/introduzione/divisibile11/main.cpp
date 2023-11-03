#include <iostream>
#include <iomanip>
#include <cmath>

/*
 * Attenzione: questa implementazione potrebbe
 * creare problemi poichè mescola gli interi (sempre precisi)
 * con i double (in generale approssimati). Il problema
 * viene risolto con la funzione round(), che fa un'approssimazione
 * all'intero più vicino, potrebbe però generare problemi con
 * gli interi long long
 */
int main() {
    int N = 121;
    int SP = 0, SD = 0;
    bool pari = true;
    int esponente = 0;
    double Nf = N;
    while(Nf > 1){
        Nf /= 10;
        esponente++;
    }
    std::cout  << Nf << " " << esponente << std::endl;

    for (int i = 0; i < esponente; ++i) {
        int cifra;
        Nf *= 10;
        cifra = round(Nf);
        std::cout <<  Nf  << " " << cifra << std::endl;
        if (pari){
            SP += cifra;
        }
        else{
            SD += cifra;
        }
        pari = !pari;
        Nf -= cifra;
    }
    if (SP - SD == 0){
        std::cout << N << " è divisibile per 11" << std::endl;
    }
    else{
        std::cout << N << " non è divisibile per 11" << std::endl;
    }
    return 0;
}
