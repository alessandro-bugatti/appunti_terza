#include <iostream>

void somma_orari(int o1, int m1, int o2, int m2,
                    int &ot, int &mt) {
    ot = o1 + o2;
    mt = m1 + m2;
    if (mt >= 60) {
        mt -= 60;
        ot += 1;
    }
}

int main() {
    // Prima versione, 2 impegni
    // int o1, m1, o2, m2, ot, mt;
    // //input
    // std::cout << "Inserisci ore e minuti del primo impegno: ";
    // std::cin >> o1 >> m1;
    // std::cout << "Inserisci ore e minuti del secondo impegno: ";
    // std::cin >> o2 >> m2;
    // //elaborazione
    // somma_orari(o1, m1, o2, m2, ot, mt);

    int o, m, ot = 0, mt = 0, N;
    std::cout << "Quanti impegni vuoi inserire? ";
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        //input
        std::cout << "Inserisci ore e minuti dell'impegno " << i + 1 << ": ";
        std::cin >> o >> m;
        //elaborazione
        somma_orari(ot, mt, o, m, ot, mt);
    }

    //output
    std::cout << "IL tempo totale impiegato è stato di "
    << ot << " ore e " << mt << " minuti.";
    return 0;
}