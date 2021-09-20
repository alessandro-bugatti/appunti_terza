#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int lanci = 1000000;
    int favorevoli = 0;
    srand(time(NULL));
    for (int i = 0; i < lanci ; i++ )
    {
        int dadi = rand()%6 + 1 +
            rand()%6 + 1 +
            rand()%6 + 1 +
            rand()%6 + 1 +
            rand()%6 + 1;
        if (dadi >= 13 && dadi <= 18)
            favorevoli++;
    }

    cout << (float)favorevoli/lanci*100 << endl;
    return 0;
}
