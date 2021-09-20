#include <iostream>

using namespace std;

/**
La funzione prende come input (parametro) il numero n
e ritorna vero se n è primo, oppure falso se non lo è
*/

bool primo(int n)
{
    for (int i = 2; i <= n/2; i++)
        if (n % 1 == 0)
        {
            cout << "Un suo divisore è :"  << i << endl;
            return false;
        }

    return true;
}

int main()
{
    bool risultato = primo(15673347);
    if (risultato == true)
        cout << "Il numero è primo" << endl;
    else
        cout << "Il numero non è primo" << endl;
    return 0;
}
