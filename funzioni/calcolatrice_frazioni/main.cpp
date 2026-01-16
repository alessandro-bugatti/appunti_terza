#include <iostream>

void somma(int n1, int d1, int n2, int d2, int &nr, int &dr) {
    nr = n1 * d2 + n2 * d1;
    dr = d1 * d2;
}

void differenza(int n1, int d1, int n2, int d2, int &nr, int &dr) {
    somma(n1, d1, -n2, d2, nr, dr);
}

void semplifica(int &n, int &d) {
    int divisore = n;
    if (d < divisore) {
        divisore = d;
    }
    for (int i = divisore; i > 1; --i) {
        if (n % i == 0 && d % i == 0) {
            n = n / i;
            d = d / i;
        }
    }
}

void stampa(int n, int d) {
    std::cout << n << "/" << d << std::endl;
}

int main() {

    int n, d;
    n = 30;
    d = 64;
    semplifica(n, d);
    stampa(n, d);
    differenza(2, 3, 2, 3, n, d);
    stampa(n, d);
    semplifica(n, d);
    stampa(n, d);
    return 0;
}