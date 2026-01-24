#include <iostream>

/**
 * Problema di esempio in cui faccio inserire
 * n voti, ne calcolo la media e conto quanti
 * voti sono sotto la media
 * @return
 */
int main() {
    const int MAX_VOTI = 30;
    int voti[MAX_VOTI];
    int n_voti = 0, sotto_media = 0;
    float media = 0;
    // voti[0] = 7;
    // voti[1] = voti[0];
    // for (int i = 0; i < 2; ++i) {
    //     std::cout << voti[i] << std::endl;
    // }
    std::cout << "Quanti voti vuoi inserire?";
    std::cin >> n_voti;
    for (int i = 0; i < n_voti; ++i) {
        std::cout << "Inserisci il voto: ";
        std::cin >> voti[i];
    }
    //POteva essere fatto anche nel ciclo precedente
    for (int i = 0; i < n_voti; ++i) {
        media += voti[i];
    }
    media /= n_voti;
    //Questo non poteva essere fatto nei for precedenti
    for (int i = 0; i < n_voti; ++i) {
        if (voti[i] < media) {
            sotto_media++;
        }
    }
    std::cout << "La tua media è " << media <<
        " e hai preso " << sotto_media << " voti sotto la media.";

    return 0;
}