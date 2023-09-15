#include <iostream>

void media_mobile(float originale[], int n, float filtrato[], int k)
{
    /*filtrato[0] = (originale[0] + originale[1])/2;
    for (int i = 1; i < n - 1; ++i) {
        filtrato[i] = (originale[i] + originale[i-1] + originale[i+1])/3;
    }
    filtrato[n-1] = (originale[n-1] + originale[n-2])/2;*/

    for (int i = 0; i < n; ++i) {
        filtrato[i] = 0;
        int conta = 0;
        for (int j = i - k; j <= i + k ; ++j) {
            if (j >= 0 && j < n) {
                filtrato[i] += originale[j];
                conta++;
            }
        }
        filtrato[i] /= conta;

    }
}

int main() {

    return 0;
}
