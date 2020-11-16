#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        float merce_venduta, guadagno = 200;
        cout << "Inserisci quanto ha venduto il venditore " <<
            i + 1 << endl;
        cin >> merce_venduta;
        if (merce_venduta <= 5000)
            guadagno += merce_venduta*5/100;
        else if (merce_venduta <= 10000)
            guadagno += 250 + (merce_venduta - 5000)*7/100;
        else
            guadagno += 250 + 350 + (merce_venduta - 10000)*9/100;
        cout << "Il venditore " << i+1 << " ha un guadagno di " <<
            guadagno << " euro" << endl;
    }
    return 0;
}
