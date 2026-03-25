#include <iostream>

const int R = 100;
const int C = 80;

void inizializza(bool m[R][C]) {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (rand() % 2 == 1) {
                m[i][j] = true;
            }
            else {
                m[i][j] = false;
            }
        }
    }
}

int quante_vive(bool m[R][C], int r, int c) {
    int conta = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1 ; ++j) {
            if (m[r + i][c + j] == true && !(i == 0 && j == 0)) {
                conta++;
            }
        }
    }
}

void evolvi(bool m[R][C]) {
    bool temp[R][C];
    for (int i = 1; i < R - 1; ++i) {
        for (int j = 1; j < C - 1; ++j) {
            int vive = quante_vive(m, i, j);
            if (m[i][j] == true && (vive == 2 || vive == 3)) {
                temp[i][j] = true;
            }

        }
    }

}

int main() {
    bool mappa[R][C];
    inizializza(mappa);
    evolvi(mappa);
    return 0;
}