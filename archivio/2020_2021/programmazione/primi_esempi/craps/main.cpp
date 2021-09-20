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
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
    #define PAUSE system("pause>nul|set/p = Premere un tasto per lanciare il dado...");
#else
    #define PAUSE system("read -p 'Premere INVIO per lanciare il dado...' continue");
#endif // WIN32

using namespace std;

int main()
{
    int  dado1, dado2, target, lancio;
    int scelta = 1;
    srand(time(NULL));
    while (scelta == 1)
    {
        PAUSE
        dado1 = rand()%6 + 1;
        dado2 = rand()%6 + 1;
        lancio = dado1 + dado2;
        cout << lancio << endl;
        if (lancio == 7)
            cout << "Hai vinto" << endl;
        else if (lancio == 2 || lancio == 3 ||lancio == 12)
            cout << "Ha vinto il banco" << endl;
        else
            {
         target = lancio;
         cout << "si continua e il tuo target vale " <<
         target << endl;
         PAUSE
         dado1 = rand()%6 + 1;
         dado2 = rand()%6 + 1;
         lancio = dado1 + dado2;
         while (lancio != target && lancio != 7)
         {
           cout << endl << "Il tuo lancio vale: " << lancio << endl;
           PAUSE
           dado1 = rand()%6 + 1;
           dado2 = rand()%6 + 1;
           lancio =dado1 + dado2;
         }
         cout << lancio << endl;
         if (lancio == target)
           cout << "Hai vinto" << endl;
         else
           cout << "Ha vinto il banco" << endl;
        }
        cout << "Vuoi giocare un'altra partita?(1-SI, 0-NO): ";
        cin >> scelta;
    }
    return 0;
}
