#include <iostream>
#include <valarray>

using namespace std;

float delta(float a, float b, float c)
{
    return b*b - 4*a*c;
}

bool soluzioni_eq_secondo_grado(float a, float b, float c,
                                float &x1, float &x2)
{
    float d = delta(a, b, c);
    if (d < 0)
        return false;
    x1 = (- b + sqrt(d))/(2*a);
    x2 = (- b - sqrt(d))/(2*a);
    return true;
}
int main() {
    float a = 4, b = 4, c = 1;
    float x1 = 0, x2 = 0;
    if (soluzioni_eq_secondo_grado(a, b, c, x1, x2) == true)
    {
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else
        cout << "Non ci sono soluzioni nel campo dei reali" << endl;
    return 0;
}
