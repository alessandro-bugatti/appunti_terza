#include <iostream>

using namespace std;

int main()
{
    int a, b, MCD;
    cout << "Inserisci i due numeri interi: ";
    cin >> a >> b;
    int minimo;
    if (a < b)
        minimo = a;
    else
        minimo = b;
    for (int i = minimo; i>=1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            MCD = i;
            i = 0;
        }
    }
    cout << "MCD: " << MCD << endl;
    return 0;
}
