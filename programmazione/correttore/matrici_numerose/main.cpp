#include <iostream>

const int MAX_RIGHE = 20, MAX_COLONNE = 20;
int m[MAX_RIGHE][MAX_COLONNE];


int main() {
    int N, M, S;
    std::cin >> M >> N >> S;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> m[i][j];
        }
    }

    //Ricerca del massimo
    int r_max = 0, c_max = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (m[i][j] > m[r_max][c_max]){
                r_max = i;
                c_max = j;
            }
        }
    }
    //Ricerca del minimo

    int r_min = 0, c_min = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (m[i][j] < m[r_min][c_min]){
                r_min = i;
                c_min = j;
            }
        }
    }
    if (S == 1){
        std::cout << m[r_max][c_max] << " " << r_max << " " << c_max
            << std::endl;
    }
    if (S == 2){
        std::cout << m[r_min][c_min] << " " << r_min << " " << c_min
                  << std::endl;
    }
    if (S == 3){
        int area = 0;
        int r_sx, c_sx, r_dx, c_dx;
        if (r_max < r_min){
            r_sx = r_max;
            r_dx = r_min;
        }
        else
        {
            r_sx = r_min;
            r_dx = r_max;
        }

        if (c_max < c_min){
            c_sx = c_max;
            c_dx = c_min;
        }
        else
        {
            c_sx = c_min;
            c_dx = c_max;
        }

        for (int i = r_sx; i <= r_dx ; ++i) {
            for (int j = c_sx; j <= c_dx; ++j) {
                area += m[i][j];
            }
        }
        std::cout << area << std::endl;
    }
    return 0;
}
