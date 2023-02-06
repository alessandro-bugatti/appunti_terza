#include <iostream>

const int N = 3;

char caratteri(int c){
    if (c == 0)
        return ' ';
    if (c == 1)
        return '*';
    return 'O';
}

/*
 * O | X | O
 * _________
 * X | X |
 * ---------
 * O |   |
 */

void stampa(int tris[][N]){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << " " << caratteri(tris[i][j]) << " ";
            if (j < 2)
                std::cout << "|";
        }
        std::cout << std::endl;
        if (i < 2)
            std::cout << "-----------" << std::endl;
    }
}

int main() {

    //0 casella vuota
    //1 giocatore 1
    //2 giocatore 2
    int tris[N][N];
    //Azzero la matrice
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tris[i][j] = 0;
        }
    }
    tris[0][1] = 1;
    tris[1][0] = 2;
    stampa(tris);

    return 0;
}
