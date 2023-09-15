#include <iostream>
#include <iomanip>

int contacifre(int n){
    int cifre = 0;
    while(n){
        cifre++;
        n/= 10;
    }
    return cifre;
}

int main() {
    const int N = 10;
    int v[N];
    srand(time(NULL));
    for(int i = 0; i < N; ++i){
        v[i] = rand();
        std::cout << i;
        for (int j = 0; j < contacifre(v[i]); ++j){
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < N; ++i){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl << std::endl;

    //Seconda versione che utilizza la libreria iomanip
    for(int i = 0; i < N; ++i){
        v[i] = rand();
        std::cout << std::setw(5) << std::left << i << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i <N; ++i){
        std::cout << std::setw(5)<< std::left << v[i] << " ";
    }
    return 0;
}
