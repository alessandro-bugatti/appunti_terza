#include <iostream>

using namespace std;

int MCD(int m, int n)
{
    int r = m % n;
    while(r != 0)
    {
        m = n;
        n = r;
        r = m % n;
    }
    return n;
}


bool semplifica(int &n, int &d)
{
    //Se il numero non è corretto
    if (d == 0)
        return false;
    //Se sono già semplificati
    if (MCD(n, d) == 1)
        return false;
    int temp = MCD(n,d);
    n = n / temp;
    d = d / temp;
    return true;
}

int main()
{
    int n = 4, m = 0;
    bool semplificato = semplifica(n, m);
    if (semplificato) //equivalente a semplificato == true
        cout << "Il numero è stato semplificato e adesso è "
            << n << "/" << m << endl;
    else
        cout << "La frazione era già ridotta ai minimi termini" << endl;
    return 0;
}
