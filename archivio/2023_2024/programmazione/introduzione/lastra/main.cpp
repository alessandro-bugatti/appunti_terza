#include <iostream>

int main() {
    int b, h, L = 0;
    int V, Vmax = 0, Lmax = 0;
    std::cout << "Inserisci il lato lungo della lastra in cm: " << std::endl;
    std::cin >> b;
    std::cout << "Inserisci il lato corto della lastra in cm: " << std::endl;
    std::cin >> h;
    //for (L = 0; L < h/2; ++L)
    while(L < h/2){
        V = ( b - 2*L) * (h - 2*L) * L;
        std::cout << V << std::endl;
        if (V > Vmax){
            Vmax = V;
            Lmax = L;
        }
        L++;
    }
    std::cout << "IL lato migliore è : "  << Lmax << std::endl;
    return 0;
}
