#include <iostream>

using namespace std;

int main() {
    //Esempio del classico Hello World
    printf("Hello world\n"); //C
    cout << "Hello world" << endl; //C++
    //Esempi con lettura e scrittura di variabili intere e float
    int a;
    float b;
    //In C
    printf("Inserisci un valore intero: ");
    scanf("%d", &a);
    //In C++
    cout << "Inserisci un valore intero: ";
    cin >> a;
    //In C
    printf("Inserisci un numero con virgola: ");
    scanf("%f", &b);
    //In C++
    cout << "Inserisci un numero con virgola: ";
    cin >> b;
    //Stampa in C
    printf("L'intero inserito vale %d e il numero con virgola vale %f\n",
           a, b);
    cout << "L'intero inserito vale " << a << " e il numero con virgola vale "
        << b << endl;
    return 0;
}
