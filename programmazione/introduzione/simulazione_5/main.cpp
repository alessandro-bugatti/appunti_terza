#include <iostream>
#include <cmath>

int main() {
    float A, B, C;
    float x, dA, dB, dMin, xMin;
    std::cout << "Inserisci le tre distanze in metri: ";
    std::cin >> A >> B >> C;
    dMin = A + sqrt(B*B + C*C);
    for (x = 0; x <  C; x += 0.01) {
        dA = sqrt(A*A + x*x);
        dB = sqrt(B*B + (C - x) * (C - x));
        if (dA + dB < dMin){
            dMin = dA + dB;
            xMin = x;
        }
    }
    std::cout << "La posizione migliore per mettere lo specchio "
                 "si trova a " << xMin << " metri dal punto 0";
    return 0;
}
