#include <iostream>

/**
 * Funziona che verifica se un anno è bisestile o no
 * @param anno L'anno da verificare
 * @return 1 se è bisestile, 0 altrimenti
 */
int bisestile(int anno){
    if (anno % 400 == 0){
        return 1;
    }
    if (anno % 100 == 0){
        return 0;
    }
    if (anno % 4 == 0){
        return 1;
    }
    return 0;
}

int main() {
    int anno = 1997;
    std::cout << "L'anno " << anno << " ha " << (365 + bisestile(anno)) << " giorni." << std::endl;
    return 0;
}
