#include <iostream>

using namespace std;

int main() {
    int a = 7, b = 5;
    //if semplice
    if (a > b)
    {
        cout << "a è maggiore di b" << endl;
        cout << "La condizione quindi era vera" << endl;
    }
    //if - else
    if (a < b)
    {
        cout << "a è minore di b" << endl;
        cout << "Quindi la condizione a < b è vera" << endl;
    }
    else
    {
        cout << "a non è minore di b" << endl;
        cout << "Quindi la condizione a < b è falsa" << endl;
    }
    return 0;
}
