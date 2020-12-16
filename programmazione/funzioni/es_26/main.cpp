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

int mcm(int m, int n)
{
    return (m*n)/MCD(m, n);
}

int main()
{
    cout << mcm(3,5)<< endl;
    cout << mcm(9,3)<< endl;
    cout << mcm(45,18)<< endl;
    return 0;
}
