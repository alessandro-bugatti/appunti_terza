#include <iostream>

float uniforme(float v, float t)
{
    float s;
    s = v * t;
    return s;
}

float accelerato(float v, float t)
{
    const float G = 9.81;
    float s;
    s = - 0.5 * G * t * t + v * t;
    return s;
}

int main() {
    float x, y;
    x = 0;
    y = 0;
    float vx, vy;
    vx = 100;
    vy = 100;
    float t = 0;
    do{
        t += 0.1;
        x = uniforme(vx, t);
        y = accelerato(vy, t);
        std::cout << "t "<<t << "-> x: " << x << " y: " << y << std::endl;
    }while(y > 0);
    return 0;
}
