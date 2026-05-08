#include <cmath>
#include <iostream>

struct Punto{
    float x;
    float y;
};

float distanza(const Punto &a,const Punto &b) {
    return std::sqrt(pow( a.x - b.x, 2) +
        pow(a.y - b.y, 2));
}

Punto punto_medio(const Punto &a,const Punto &b) {
    Punto ris;
    ris.x = (a.x + b.x) / 2;
    ris.y = (a.y + b.y) / 2;
    return ris;
}

int main() {
    Punto p1, p2, medio;
    p1.x = 9;
    p1.y = 4;
    p2.x = 3;
    p2.y = 2;
    std::cout << distanza(p1, p2) << std::endl;
    medio = punto_medio(p1, p2);
    std::cout << medio.x << ", " << medio.y << std::endl;
    return 0;
}
