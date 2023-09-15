#include <iostream>

const int N = 3;

int massimo(int m[][N], int &r, int &c){
    r = 0;
    c = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (m[i][j] > m[r][c]){
                r = i;
                c = j;
            }
        }
    }
    return m[r][c];
}

int main() {
    int m[N][N];
    std::cout << "Inserisci i valori della matrice: "  << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << i << " " << j << " : ";
            std::cin >> m[i][j];
        }
    }
    int r, c, max;
    max = massimo(m, r, c);
    std::cout << "Il valore massimo è " << max << " e si trova in posizione"
        << r << ", " << c << std::endl;
    return 0;
}
