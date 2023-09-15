#include <iostream>

int main() {
    int numero_colori, larghezza, altezza;
    std::cout << "Inserisci il numero di colori" << std::endl;
    std::cin >> numero_colori;
    int numero_bit = 0;
    int potenza = 1;
    while (potenza < numero_colori){
        potenza *= 2;
        numero_bit++;
    }
    //std::cout << numero_bit << std::endl;
    std::cout << "Inserisci larghezza e altezza dell'immagine" << std::endl;
    std::cin >> larghezza >> altezza;
    int peso_immagine = larghezza * altezza * numero_bit / 8;
    if (larghezza * altezza * numero_bit % 8 != 0){
        peso_immagine++;
    }
    int peso_palette = numero_colori * 3;
    int peso_totale = peso_immagine + peso_palette;
    std::cout << "Il peso dell'immagine è " << peso_totale << " byte." << std::endl;
    return 0;
}
