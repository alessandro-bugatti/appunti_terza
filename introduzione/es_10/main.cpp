#include <iostream>

int main()
{
    float voto, media, somma=0;
    int n_voti = 0;
    std::cout << "inserisci un voto: ";
    std::cin >> voto;
    while (voto > 0)
    {
        somma=somma+voto; //somma+=voto;
        n_voti++;
        media=somma/n_voti;
        std::cout << "La media è: " << media << " ed è calcolata su " << n_voti
            << " voti " << std::endl;
        std::cout << "inserisci un voto: ";
        std::cin >> voto;
    }
    return 0;
}