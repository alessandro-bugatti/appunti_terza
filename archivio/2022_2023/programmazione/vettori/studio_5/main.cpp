#include <iostream>

int main() {
    const int N = 50;
    int v[N];
    int n_elementi;
    std::cout << "Quanti valori vuoi inserire? ";
    std::cin >> n_elementi;
    for (int i = 0; i < n_elementi; ++i) {
        std::cin >> v[i];
    }
    //Inverte gli elementi nel vettore
    int j = n_elementi - 1;
    for (int i = 0; i < n_elementi/2 ; ++i) {
        //Scambio l'elemento i-esimo con l'elemento j-esimo
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        j--;
    }
    //Stampa gli n_elementi del vettore
    for (int i = 0; i < n_elementi; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
