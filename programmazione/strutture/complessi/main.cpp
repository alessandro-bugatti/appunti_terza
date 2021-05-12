#include <iostream>

using namespace std;

struct Complesso{
    float re;
    float im;
};

Complesso somma(Complesso a, Complesso b)
{
    Complesso c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}

Complesso differenza(Complesso a, Complesso b)
{
    Complesso c;
    b.re = -b.re;
    b.im = -b.im;
    c = somma(a, b);
    return c;
}

void stampa(Complesso c)
{
    if (c.re == 0 && c.im == 0)
        cout << 0;
    else
    {
        if (c.re != 0)
            cout << c.re << " ";
        if (c.im == 1.0)
            cout << "+i";
        else if (c.im == -1.0)
            cout << "-i";
        else if (c.im < 0)
            cout << "- " << -c.im << "i";
        else if (c.im > 0)
            cout << "+ " << c.im << "i";
    }

}


int main()
{
    Complesso a = {3.4, 2.1} , b ={5.3, 6.8};
    Complesso f = {5.7, 1.3};
    /*cout << "Inserisci la parte reale: ";
    cin >> a.re;
    cout << "Inserisci la parte immaginaria: ";
    cin >> a.im;*/
    //Complesso d = somma(a, b);
    //Complesso c = somma(f, d);
    Complesso c = somma(f, somma(a, b));
    stampa(c);
    cout << endl;
    c = differenza(a, f);
    stampa(c);
    cout << endl;
    c.re = 0;
    c.im = -1.0;
    stampa(c);
    cout << endl;
    c.re = 0;
    c.im = 0;
    stampa(c);
    cout << endl;
    c.re = -3.0;
    c.im = -7.0;
    stampa(c);
    cout << endl;
    c.re = 8;
    c.im = -1.5;
    stampa(c);
    cout << endl;
    c.re = 0;
    c.im = 1.0;
    stampa(c);

    return 0;
}
