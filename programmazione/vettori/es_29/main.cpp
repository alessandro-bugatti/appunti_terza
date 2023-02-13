#include <iostream>

const int N = 3;

bool simmetrica(int m[][N])
{
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if(m[i][j] != m[j][i])
                return false;
        }
    }
    return true;
}

int main() {
    int m[N][N] ={
            {1, 2, 3},
            {2, 4, 7},
            {3, 7, 11}
    };
    std::cout << simmetrica(m) << std::endl;
    return 0;
}
