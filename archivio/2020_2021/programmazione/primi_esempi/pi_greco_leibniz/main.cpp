#include <iostream>

using namespace std;

int main()
{
    int numero_termini;
    double denominatore = 1;
    double pi_greco = 0;
    int segno = 1;
    cout << "Inserisci il numero di termini per fare l'approssimazione del pi greco: ";
    cin >> numero_termini;
    for (int i = 0; i < numero_termini; i++)
    {

        pi_greco = pi_greco + 1/denominatore*segno;
        //Per visualizzare la serie
        if (segno == 1)
            cout << "+" << "1/" << denominatore;
        else
            cout << "-" << "1/" << denominatore;
        if (segno == 1)
            segno = -1;
        else
            segno = 1;
        //cout << "Segno " << segno << endl;
        denominatore = denominatore + 2;
//        pi_greco = pi_greco + segno/denominatore;
//        segno = -segno;
//        denominatore = denominatore + 2;
    }
    cout << endl <<  "Il valore di pi greco approssimato vale " << 4*pi_greco << endl;
    return 0;
}
