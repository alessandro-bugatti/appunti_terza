#include <iostream>

using namespace std;

int main()
{
    int N, D;
    int MCD;
    int segno;
    cin >> N >> D;
    if ( N*D > 0)
        segno = 1;
    else
        segno = -1;
    if (N < 0)
        N = -N;
    if (D < 0)
        D = -D;

    //Calcolare il MCD

    for (int i = D; i >= 1; i--)
    {
        if (N % i == 0 && D % i == 0)
        {
            MCD = i;
            i = 0;
        }
    }
    N = N / MCD;
    D = D / MCD;
    if (D != 1)
        cout << segno*N << "/" << D << endl;
    else
        cout << segno*N << endl;
    return 0;
}
