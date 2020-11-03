//Gioco Craps
//
//Regole
//Si lanciano sempre 2 dadi da sei
//
//Al primo lancio:
//    • esce 7, il giocatore vince
//    • esce 2, 3 o 12, il banco vince
//    • in tutti gli altri casi, il primo lancio diventa il target
//
//Nel terzo caso si continuano a tirare i dadi fino a che:
//    • esce il target, il giocatore vince
//    • esce 7, il banco vince

#include <iostream>

using namespace std;

int main()
{
    int dado1, dado2, target, lancio;
    dado1 = rand()%6 + 1;
    dado2 = rand()%6 + 1;
    lancio = dado1 + dado2;
    if (lancio == 7)
        cout << "Hai vinto" << endl;
    else if (lancio == 2 || lancio == 3 || lancio == 12)
        cout << "Hai perso" << endl;
    else
    {

    }

    return 0;
}
