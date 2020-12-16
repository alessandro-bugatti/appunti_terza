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



bool prodotto(int n1, int d1, int n2, int d2, int &nr, int &dr)
{
    if (d1 == 0 || d2 == 0)
        return false;
    nr = n1 * n2;
    dr = d1 * d2;
    cout <<nr << "/" << dr << endl;
    semplifica(nr, dr);
    cout <<nr << "/" << dr << endl;
    return true;
}

int main()
{
    int n1 = 12, d1 = 49;
    int n2 = 21, d2 = 55;
    int nr, dr;
    prodotto(n1, d1, n2, d2, nr, dr);
    cout << "Il risultato del prodotto è " << nr << "/" << dr
        << endl;
    return 0;
}
