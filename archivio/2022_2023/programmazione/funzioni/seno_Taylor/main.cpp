#include <iostream>
#include <cmath>
double potenza(double b, int e){
    int risultato = 1;
    for (int i = 0; i < e; ++i) {
        risultato *= b;
    }
    return risultato;
}

int fattoriale(int n){
    int risultato = 1;
    for (int i = 1; i <= n ; ++i) {
        risultato *= i;
    }
    return risultato;
}

double my_sin(double x, int n){
    double risultato = 0;
    for (int i = 0; i < n; ++i) {
        risultato += potenza(-1, i) /
                fattoriale(2*i + 1) *
                potenza(x, 2*i + 1);
    }
    return risultato;
}

int main() {
    double x = 1;
    std::cout << "Funzione seno della libreria: " << sin(x) << std::endl;
    std::cout << "Funzione seno sviluppata come serie di Taylor" << std::endl;
    for (int i = 1; i < 10; ++i) {
        std::cout << "Calcolo con " << i << " termini: " << my_sin(x, i) << std::endl;
    }
    return 0;
}
