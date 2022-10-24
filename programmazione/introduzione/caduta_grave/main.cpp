#include <iostream>

int main() {
    float altezza_iniziale, altezza_corrente, tempo;
    std::cout << "Inserisci l'altezza: ";
    std::cin >> altezza_iniziale;
    tempo = 0;
    altezza_corrente = altezza_iniziale;
    //Struttura di un ciclo indeterminato
    //IL while cicla finchè la condizione è vera
    while(altezza_corrente > 0)
    {
        std::cout << "t : " << tempo << " h: " << altezza_corrente << std::endl;
        tempo += 0.001;
        altezza_corrente = altezza_iniziale - 0.5 * 9.81 * tempo * tempo;
    }
    return 0;
}
