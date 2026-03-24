#include <iostream>

const int N = 1000;

bool controlla_cornice(int m[N][N]) {
    int neri = 0, totali = 4*N - 4;
    for (int i = 0; i < N; ++i) {
        if (m[0][i] <= 10) {
            neri++;
        }
        if (m[N - 1][i] <= 10) {
            neri++;
        }
        if (m[i][0] <= 10) {
            neri++;
        }
        if (m[i][N-1] <= 10) {
            neri++;
        }
    }
    if (neri > 0.9*totali) {
        return true;
    }
    return false;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}