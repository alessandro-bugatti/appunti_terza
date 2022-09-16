#include <iostream>

using namespace std;

int main() {
    //Esempio di utilizzo di uno switch per stabilire il numero
    //di giorni di un mese
    int mese;
    cout << "Inserisci il numero del mese che ti interessa" << endl;
    cin >> mese;
    switch (mese) {
        case 2:
            cout << "Il mese ha 28 giorni" << endl;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout << "Il mese ha 30 giorni" << endl;
            break;
        default:
            cout << "Il mese ha 31 giorni" << endl;
    }
    if (mese == 2){
        cout << "Il mese ha 28 giorni" << endl;
    }
    else if (mese == 4 || mese == 6 || mese == 9 || mese == 11){
        cout << "Il mese ha 30 giorni" << endl;
    }
    else{
        cout << "Il mese ha 31 giorni" << endl;
    }

    return 0;
}
