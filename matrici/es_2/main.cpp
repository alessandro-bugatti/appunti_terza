#include <iostream>

const int W = 640;
const int H = 480;

int conta_rocce(int m[H][W]) {
    int rocce = 0;
    for (int i = 0; i < H; ++i) {
        int conta = 0;
        for (int j = 0; j < W; ++j) {
            if (m[i][j] == 0) {
                conta++;
            } else {
                if (conta >= 10) {
                    rocce++;
                }
                conta = 0;
            }
        }
        if (conta >= 10) {
            rocce++;
        }
    }
    return rocce;
}


int main() {
    int m[H][W];
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            m[i][j] = 1;
        }
    }

    for (int i = 23; i < 43; ++i) {
        m[55][i] = 0;
    }

    for (int i = 103; i < 143; ++i) {
        m[55][i] = 0;
    }
    std::cout << "Numero rocce: " << conta_rocce(m) << std::endl;
    return 0;
}