#include <iostream>

int main()
{
    int N=5 , n_asterischi=1 , n_spazi;
    n_spazi=N-1;
    for (int i = 0; i < N; ++i) {
        //singola riga di lunghezza N
        for (int j = 0; j < N; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < n_spazi; ++j) {
            std::cout << " ";

        }
        for (int j = 0; j < n_asterischi; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
        n_asterischi+=2;
        n_spazi--;
    }
    n_spazi=1;
    n_asterischi-=4;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < n_spazi; ++j) {
            std::cout << " ";

        }
        for (int j = 0; j < n_asterischi; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
        n_asterischi-=2;
        n_spazi++;
    }

    return 0;
}