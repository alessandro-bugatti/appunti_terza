#include <iostream>

using namespace std;

int main()
{
    const int N = 1000;
    int v[N];
    for (int i = 0; i < N; i++)
        v[i] = rand()%20 - 10;
    for (int i = 0; i < N; i++)
    {
        //Soluzione non corretta, ma che contiene
        //dei germogli di un'idea corretta
        if (v[i] > 0 && v[i+1] > 0 && v[i+2] > 0)
            cout << v[i] << " " << v[i+1] << " "
            << v[i+2] << " ";
    }
    return 0;
}
