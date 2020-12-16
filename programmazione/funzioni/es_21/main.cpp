#include <iostream>

using namespace std;

//Soluzione richiesta dal libro
void arrotonda(float &n)
{
    //Primo algoritmo
    int n1 = n + 0.5;
    n = n1;
}

//Soluzione alternativa
float arrotonda2(float n)
{
    //Secondo algoritmo
    int n1 = n; //se n = 2.3 -> n1 = 2
    if (n - n1 < 0.5)
        return n1;
    else
        return n1 + 1;
}


int main()
{
    float n = 2.51;
    arrotonda(n);
    cout << n << endl;
    n = 2.3;
    n = arrotonda2(n);
    cout << n << endl;
    return 0;
}
