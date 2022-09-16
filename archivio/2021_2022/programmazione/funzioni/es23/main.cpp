#include <iostream>

using namespace std;

int collatz(int n)
{
    int contatore = 0;
    while(n != 1)
    {
        cout << n << " -> ";
        if (n % 2 == 0)
            n /= 2;
        else
            n = n*3 + 1;
        contatore++;

    }
    return contatore + 1;
}



int main() {
    int a = 7, b = 22;
    for (int i = a; i <= b ; ++i) {
        cout << "Sequenza (" <<i << "): ";
        int l = collatz(i);
        cout << "1 Lunghezza: " << l << endl;
    }

    return 0;
}
