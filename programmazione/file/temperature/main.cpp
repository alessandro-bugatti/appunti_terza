#include <iostream>
#include <fstream>
int main() {
    std::ifstream temperature("temperature.txt");
    if (!temperature) {
        std::cout << "Errore nell'apertura" << std::endl;
        return 1;
    }
    float somma = 0;
    for (int i = 0; i < 10; ++i) {
        float temp;
        temperature >> temp;
        somma += temp;
    }
    /* Questa parte al posto della precedente se non si sa quanti sono i numeri,
     * a cui va poi aggiunto un contatore
    float temp;
    while (temperature >> temp) {
        somma += temp;
    }
    */
    std::cout << "La media delle temperature è " << somma/10 << std::endl;
    temperature.close();
    return 0;
}