#include <iostream>

int main() {
    //Variabile intera
    int a;
    //Variabile floating point
    float b;
    //Scrittura a video
    std::cout << "Inserisci un valore intero: ";
    //Lettura da tastiera
    std::cin >> a;
    //Operazione matematica e assegnamento
    b = 7 * a;
    //Stampa del risultato
    std::cout << "Il valore che hai inserito cioè " << a << " moltiplicato per 7 risulta " <<
        b << std::endl;
    //Selezione con if-else
    if (a > 10){
        std::cout << "Il valore inserito è maggiore di 10" << std::endl;
        a = b * 4;
        std::cout << "Il nuovo valore di a è diventato " << a << std::endl;
    }else{
        std::cout << "Il valore di a è minore o uguale a 10" << std::endl;
    }

    return 0;
}
