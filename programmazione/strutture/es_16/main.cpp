#include <iostream>
#include <cmath>

using namespace std;

struct Punto{
    double x;
    double y;
};

Punto punto_medio(Punto a, Punto b)
{
    Punto medio;
    medio.x = (a.x + b.x)/2;
    medio.y = (a.y + b.y)/2;
    return medio;
}

void stampa(Punto p)
{
    cout << "(" << p.x << ";" << p.y << ")" << endl;
}

double distanza(Punto a, Punto b)
{
    double d;
    d = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    return d;
}

int leggi_punti(Punto v[])
{
    int n_punti = 0;
    ifstream in("punti.txt");
    if (!in)
        return -1;
    double x, y;
    while (in >> x >> y)
    {
        v[n_punti].x = x;
        v[n_punti].y = y;
        n_punti++;
    }
    return n_punti;
}

double lunghezza_spezzata(Punto v[],int n_punti)
{
    double d = 0;
    for (int i = 0; i < n_punti - 1; i++)
        d += distanza(v[i], v[i+1]);
    return d;
}

int main()
{
    const int DIM = 100;
    Punto a = {2,3}, b = {5,7};
    Punto v[DIM];
    int n_punti = 0;
    n_punti = leggi_punti(v);
    Punto c = punto_medio(a,b);
    cout << c << endl;
    stampa(punto_medio(a,b));
    double d = distanza(a, b);
    cout << d << endl;
    return 0;
}
