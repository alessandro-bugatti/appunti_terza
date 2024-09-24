#include <iostream>
#include <valarray>

using namespace std;

int main() {
    float v_iniziale;
    float angolo;
    float vx, vy;
    float g = 9.81;
    float x , y;
    float t = 0;
    cout << "immeti la velocità iniziale in metri al secondo: " << endl;
    cin >> v_iniziale;
    cout << "immeti l'angolo in radianti: " << endl;
    cin >> angolo;
    vx = v_iniziale * cos(angolo);
    vy = v_iniziale * sin(angolo);
    do{
        cout << "x : " << x << " y: " << y << endl;
        t += 0.1; //t = t + 0.1;
        x = vx * t;
        y = vy * t - 0.5 * g * t * t;
    }while(y > 0);
    return 0;

}
