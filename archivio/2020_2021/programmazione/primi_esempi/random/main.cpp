#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int valore_dado;
    //Inizializza il seme del generatore di numeri casuali
    srand(time(NULL));
    for (int i = 0; i < 20; i++)
    {
        //srand(time(NULL)); //NOOOOO!!!!!
        valore_dado = rand();
        cout << "Valore uscito: " <<
            valore_dado << " -> " <<
            (valore_dado%6 + 1)
             << endl;
    }
    return 0;
}
