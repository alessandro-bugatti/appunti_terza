#include <cmath>
#include <iostream>

float distanza(float x1, float y1, float x2, float y2) {
    float dx = x1 - x2;
    float dy = y1 - y2;
    float d = sqrt(dx*dx + dy*dy);
    return d;
}

int main() {
    float x1 = 2, y1 = -3, x2 = 8.9, y2 = 13.33, x3 = 12, y3 = 4.5;
    float P = distanza(x1, y1, x2, y2);
    P += distanza(x2,y2,x3,y3);
    P += distanza(x1, y1, x3, y3);

    std::cout << "La distanza è " << P << std::endl;
    return 0;
}