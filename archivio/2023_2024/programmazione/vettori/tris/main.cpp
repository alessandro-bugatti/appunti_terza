#include <iostream>

const int DIM = 3;

void stampa_tris(int tris[][DIM], int n){
    for (int i = 0; i < n; ++i) {
        std::cout << tris[i][0] << " | " << tris[i][1]
                  << " | " << tris[i][2] << std::endl;
        if (i < DIM - 1)
            std::cout << "________________" << std::endl;
    }
}

int main() {

    int tris[DIM][DIM];
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            tris[i][j] = 0;
        }
    }

    stampa_tris(tris, DIM);

    int r, c;
    std::cin >> r >> c;
    while ( r > DIM || r < 1 ||
                c > DIM || c < 1
            || tris[r-1][c-1] != 0){
        std::cin >> r >> c;
    }

    int vittoria = 0;
    for (int i = 0; i < DIM; ++i) {
        if (tris[i][0] != 0 && tris[i][0] == tris[i][1]
            && tris[i][1] == tris[i][2])
            vittoria = tris[i][0];
    }

    return 0;
}
