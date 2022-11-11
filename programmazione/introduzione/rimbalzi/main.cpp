#include <iostream>

int main() {
    float H, H_i;
    const float ALTEZZA_MINIMA = 0.001; //Un millimetro
    int rimbalzi = 0;
    const float COSTANTE_ELASTICA = 0.99;
    std::cout << "Inserisci l'altezza di partenza della pallina in metri: " << std::endl;
    std::cin >> H;
    H_i = H;
    while(H > ALTEZZA_MINIMA){
        H *= COSTANTE_ELASTICA; // H = H - (1 -COSTANTE_ELASTICA)*H
        rimbalzi++;
    }
    std::cout << "La pallina, cadendo da " << H_i << " metri, farà " << rimbalzi << " rimbalzi prima di fermarsi"
        << std::endl;
    return 0;
}
