#include <iostream>
#include <vector>

void inverti(int v[], int n) {
    for (int i = 0; i < n / 2 ; ++i) {
        int temp = v[i];
        v[i] = v[n - i - 1];
        v[n - i - 1] = temp;
    }
}

void stampa(const int v[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void stampa(const  std::vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int DIM = 10;
    int v1[DIM]; //Vettore nativo
    std::vector<int> v2; //Classe vector
    for (int i = 0; i < DIM; ++i) {
        v1[i] = rand()%100;
        v2.push_back(v1[i]);
    }
    //Overloading delle funzioni
    stampa(v1, DIM);
    stampa(v2);

    inverti(v1, DIM);
    stampa(v1, DIM);
    return 0;
}
