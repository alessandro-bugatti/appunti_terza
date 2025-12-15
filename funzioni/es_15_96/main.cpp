#include <iostream>

using namespace std;

float calcolaStipendio(float oreOrd, float valOreOrd,float oreStra, float valOreStra,
                    float &lordo, float &tasse) {
    lordo = oreOrd * valOreOrd + oreStra * valOreStra;
    tasse = 0;

    if (lordo > 5000) {
        if (lordo <= 22000)
            tasse = (lordo - 5000) * 0.22;
        else if (lordo <= 50000)
            tasse = (22000 - 5000) * 0.22 +
                    (lordo - 22000) * 0.33;
        else
            tasse = (22000 - 5000) * 0.22 +
                    (50000 - 22000) * 0.33 +
                    (lordo - 50000) * 0.38;
    }

    return lordo - tasse;
}

int main() {
    float oreOrd, oreStra, valOreOrd, valOreStra;
    float lordo, tasse, netto;
    char scelta;

    cout << "Inserisci la paga per le ore ordinarie: ";
    cin >> valOreOrd;
    cout << "Inserisci la paga per le ore straordinarie: ";
    cin >> valOreStra;

    do {
        cout << "Inserisci ore ordinarie lavorate: ";
        cin >> oreOrd;

        cout << "Inserisci ore straordinarie lavorate: ";
        cin >> oreStra;

        // Possibilità di modificare la paga per il prossimo dipendente
        char modificaPaga;
        cout << "\nVuoi modificare la paga oraria rispetto a quella standard? (s/n): ";
        cin >> modificaPaga;

        if (modificaPaga == 's' || modificaPaga == 'S') {
            float valOreOrd, valOreStra;
            cout << "Nuova paga ordinaria: ";
            cin >> valOreOrd;
            cout << "Nuova paga straordinaria: ";
            cin >> valOreStra;
            netto = calcolaStipendio(oreOrd, valOreOrd, oreStra, valOreStra, lordo, tasse);
        } else {
            netto = calcolaStipendio(oreOrd, valOreOrd, oreStra, valOreStra, lordo, tasse);
        }



        cout << "\n--- Riepilogo stipendio ---\n";
        cout << "Stipendio lordo: " << lordo << " euro\n";
        cout << "Tasse da detrarre: " << tasse << " euro\n";
        cout << "Stipendio netto: " << netto << " euro\n";

        cout << "\nVuoi calcolare lo stipendio di un altro dipendente? (s/n): ";
        cin >> scelta;

        cout << "\n";

    } while (scelta == 's' || scelta == 'S');

    cout << "Fine dei calcoli.\n";
    return 0;
}
