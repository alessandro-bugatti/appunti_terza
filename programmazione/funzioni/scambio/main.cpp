#include <iostream>

using namespace std;

//void vuol dire che non restituisce nulla
//In questo esempio usiamo un passaggio per riferimento
void scambio(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a, b;
    //Per evitare l'input le assegno direttamente
    a = 5;
    b = 17;
    cout << "Prima dello scambio" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    scambio(a, b);
    cout << "Dopo lo scambio" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}
