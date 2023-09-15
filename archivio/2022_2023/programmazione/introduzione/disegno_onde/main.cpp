#include <iostream>

/*
 *
  _     _     _
/ \   / \   / \
   \_/   \_/   \_/
 */

int main() {
    int N = 3;
    //Prima riga
    for (int i = 0; i < N; ++i) {
        std::cout << " _    ";
    }
    std::cout << std::endl;

    //Come stampare il simbolo \, che essendo il carattere di escape
    //ha bisogno di essere "duplicato" per ottenere la stampa di un singolo \
    // std::cout << "\\"; stampa un singolo slash

    //Seconda riga
    return 0;
}
