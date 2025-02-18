#include <iostream>

void riempi(int v[], int n) {
    for (int i = 0; i < n; ++i) {
        v[i] = rand()%100 + 1;
    }
}

/**
 *
 * @param v
 * @param n
 * @return posizione dell'elemento di valore massimo
 */
int massimo(int v[], int n) {
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] > v[pos]) {
            pos = i;
        }
    }
    return pos;
}

int mediano(int v[], int n) {
    for (int i = 0; i < n / 2; ++i) {
        int m = massimo(v, n);
        v[m] = -1;
    }
    int med = massimo(v, n);
    return v[med];
}

int main() {
    const int N = 100;
    int v[N];
    riempi(v, N);
    std::cout << "Il mediano è " << mediano(v, N) << std::endl;
    return 0;
}