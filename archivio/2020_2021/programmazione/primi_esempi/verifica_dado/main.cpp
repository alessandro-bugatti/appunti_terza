#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0,
        c5 = 0, c6 = 0;
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        int dado = rand()%6 + 1;
        if (dado == 1)
            c1++;
        if (dado == 2)
            c2++;
        if (dado == 3)
            c3++;
        if (dado == 4)
            c4++;
        if (dado == 5)
            c5++;
        if (dado == 6)
            c6++;
    }
    cout << " 1 -> " << c1 << endl;
    cout << " 2 -> " << c2 << endl;
    cout << " 3 -> " << c3 << endl;
    cout << " 4 -> " << c4 << endl;
    cout << " 5 -> " << c5 << endl;
    cout << " 6 -> " << c6 << endl;
    return 0;
}
