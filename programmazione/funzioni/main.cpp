#include <iostream>
#include <math.h>

double calcola_circonferenza(double raggio) {
    double c = raggio * 2 * M_PI;
    return c;
}
int somma(int a, int b) {
    int somma = a + b;
    return somma;
}

int doppio(int a) {
    return a*2;
}

float positivo (float a) {
    if (a<0) {
        a=-a;
    }
    return a;
}

bool pari (int N) {
    if (N % 2 == 0) {
        return true;
    }
    return false;
}

int maggiore(int a,int b) {
    if (a<b) {
        return b;
    }
    return a;
}

int area (int h, int b) {
    int area = h * b;
    return area;
}
int sommaN(int n) {
    int somma = 0;
    for (int i=1; i<=n; i++) {
        somma += i;
    }
    return somma;
}

int main() {
    int v = rand() % 10;
    std::cout << v << std::endl;
    std::cout << rand() << std::endl;
    std::cout << calcola_circonferenza(v) << std::endl;
    return 0;
}
