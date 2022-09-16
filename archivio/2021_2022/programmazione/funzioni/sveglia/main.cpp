#include <iostream>

using namespace std;

int converti_orario_minuti(int ore, int minuti)
{
    int totale;
    totale = ore*60 + minuti;
    return totale;
}

int main() {
    int ora_inizio = 18, minuti_inizio = 01,
        ora_sveglia = 6, minuti_sveglia = 30;
    int minuti_totale_attuale;
    int minuti_totale_sveglia;
    int minuti_passati;
    minuti_totale_attuale = converti_orario_minuti(ora_inizio, minuti_inizio);
    minuti_totale_sveglia = converti_orario_minuti(ora_sveglia, minuti_sveglia);
    //Caso in cui sono nello stesso giorno
    if (minuti_totale_attuale < minuti_totale_sveglia)
        minuti_passati = minuti_totale_sveglia - minuti_totale_attuale;
    else
        minuti_passati = minuti_totale_sveglia + 24*60 - minuti_totale_attuale;
    cout << "Ore: " << minuti_passati/60 <<
            " minuti: " << minuti_passati%60 << endl;
    return 0;
}
