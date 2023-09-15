#include <iostream>

int main() {
    int N; //Esponente di 2^N
    float risultato = 1;
    std::cout << "Inserisci l'esponente: ";
    std::cin >> N;
    //Se N è solo positivo questa è la soluzione
//    for(int i = 0; i < N; ++i){ //++i è equivalente a i = i + 1;
//        risultato *= 2; //risultato = risultato * 2;
//    }
    //Con N che può essere anche negativo, prima soluzione più rozza
//    if (N > 0){
//        for(int i = 0; i < N; ++i){ //++i è equivalente a i = i + 1;
//            risultato *= 2; //risultato = risultato * 2;
//        }
//    }
//    else
//    {
//        //Esempio 2 ^ -3 = 1/8 = 1/2 * 1/2 * 1/2
//        //Trasformo l'esponente in un numero positivo
//        int Npos = -N;
//
//        for(int i = 0; i < Npos; ++i){ //++i è equivalente a i = i + 1;
//            risultato /= 2; //risultato = risultato / 2;
//        }
//    }

    //Soluzione con N che può essere negativo, più elegante
    bool negativo = false;
    if (N < 0) {
        negativo = true;
        N = -N;
    }
    for(int i = 0; i < N; ++i){ //++i è equivalente a i = i + 1;
        risultato *= 2; //risultato = risultato * 2;
    }
    if (negativo == true){
        risultato = 1 / risultato;
        N = -N;
    }
    std::cout << "2 elevato alla " << N << " è uguale a " << risultato << std::endl;

    return 0;
}
