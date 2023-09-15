#include <iostream>

long long fattoriale(int n) {
    if (n == 0)
        return 1;
    long long risultato = 1;
    for (int i = 1; i <= n ; ++i) {
        risultato *= i;
    }
    return risultato;
}

double e(int N){
    double risultato = 1;
    double uno = 1;
    for (int i = 1; i < N; ++i) {
        risultato = risultato + uno / fattoriale(i);
    }
    return risultato;
}



int main() {
    std::cout << e(11) << std::endl;
    float f = 123.456789E33 ;
    int i = 123456789;
    std::cout << f << " " << i << std::endl;
    f = i;
    std::cout << f << " " << i << std::endl;
    return 0;
}
