#include <iostream>
#include <iomanip>

int main()
{
    double N;
    double a, b, medio;
    /* Una variabile costante è una variabile il cui valore
     * non può essere modificato ma solo letto. Serve
     * per dare un nome significativo a dei valori che altrimenti
     * sarebbero solo dei numeri
     */

    const double epsilon = 0.0000000001;
    std::cout << "Inserisci un numero positivo: ";
    std::cin >> N;
    if (N >= 1){
        a = 0;
        b = N;
    }else{
        a = N;
        b = 1;
    }
    while(b - a > epsilon)
    {
        medio = (a + b)/2;
        if( medio*medio > N)
            b = medio;
        else
            a = medio;
    }
    std::cout << "La radice è " << medio << std::endl;
    std::cout << "La radice è " << std::setprecision(13) << medio << std::endl;

    return 0;
}
