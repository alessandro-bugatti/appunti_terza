#include <iostream>

using namespace std;

int main() {
    int a = 7, b = 5;
    //ciclo while
    while(a >= b && b > 0 || a > 0)
    {
        cout << a << " - " << b << endl;
        a = a - 1;
    }
    return 0;
}
