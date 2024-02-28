#include <iostream>
#include <vector>

void shift_uno(int v[], int n){
    int temp = v[n - 1];
    for (int i = n - 2; i >= 0 ; --i) {
        v[i + 1] = v[i];
    }
    v[0] = temp;
}

void shift(int v[], int n, int k){
    //Prima idea: ripeto lo shift circolare di una posizione k volte
    k = k % n;
    for (int i = 0; i < k; ++i) {
        shift_uno(v, n);
    }
}

void shift_vector(std::vector<int> &v, int k){
    for (int i = 0; i < k; ++i) {
        int temp = v.at(v.size() - 1);
        v.pop_back();
        v.insert(v.begin(), temp);
    }
}

int main() {
    int v[] = {1,2,3,4,5};
    shift(v, 5, 3);
    for (int i = 0; i < 5; ++i) {
        std::cout << v[i] << " ";
    }
    return 0;
}
