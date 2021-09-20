#include <iostream>

using namespace std;

int compresi(int v[], int n, int minimo, int massimo)
{
    int cont = 0;
    for (int i = 0; i < n; i++)
        if (v[i] > minimo && v[i] < massimo)
            cont++;
    return cont;
}

int main()
{
    int v[] = {2,34,43,56,22};
    cout << compresi(v, 5, 40, 60) << endl;
    return 0;
}
