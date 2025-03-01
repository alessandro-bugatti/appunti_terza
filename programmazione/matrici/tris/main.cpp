#include <iostream>

const int DIM = 3;

void riempi (int tris[][DIM]){
    for (int i=0; i<DIM; ++i){
        for (int j=0; j<DIM; ++j){
            tris[i][j]=0;
        }
    }
}

char converti(int n) {
    if (n == 1) {
        return 'X';
    }
    if (n == 2) {
        return 'O';
    }
    return ' ';
}

bool mossa_valida(int tris[][DIM], int r, int c) {
    if (r < 0 || r >= DIM)
        return false;
    if (c < 0 || c >= DIM)
        return false;
    if (tris[r][c] != 0)
        return false;
    return true;
}

void stampa(int tris[][DIM]) {
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            std::cout << " " << converti(tris[i][j]) << " ";
            if (j != DIM - 1) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
        if (i != DIM - 1) {
            for (int j = 0; j < DIM*4 - 1; ++j) {
                std::cout << "-";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    int tris[DIM][DIM];
    riempi (tris);
    stampa(tris);
    tris[1][1] = 1;
    tris[1][2] = 2;
    stampa(tris);
    return 0;
}