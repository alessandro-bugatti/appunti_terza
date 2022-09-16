#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>

/**
 * @author Rocca
 */
using namespace std;
//Sono state implementate TUTTE le funzionalità
int main() {


    setlocale(LC_ALL, "C");         // impostazioni lingua ( risolve problemi lettere accentate)

    const int MAX = 1000;

    srand(time(NULL));
    int numero_da_indovinare = rand() % MAX + 1;


    int tentativo, monete = 100, pgiocate = 0, pvinte = 0, gioco = 0, modifica, monetescommesse;

    while (gioco != 3) {


        cout << "_____________________________" << endl;
        cout << "|     CASINO CASTELLI       |" << endl;
        cout << "|                           |" << endl;
        cout << "|-> Monete disponibili: " << monete << endl;
        cout << "|-> Partite vinte: ";
        if (pgiocate == 0) {
            cout << "N/A" << endl;
        } else {
            cout << pvinte << " su " << pgiocate << endl;
        }
        cout << "|                           |" << endl;
        cout << "|___________________________|" << endl;

        cout << "- - - - - - - - - - - - - - - - - -" << endl;

        cout << "1. INDOVINA IL NUMERO" << endl;
        cout << "2. BLACKJACK" << endl;
        cout << "3. esci dal casino" << endl;
        cout << endl;
        cout << "Scegli il gioco: ";
        cin >> gioco;
        if (gioco!=3) {
            cout << "quante monete vuoi scommettere?" << endl;
            cin >> monetescommesse;
            while (monetescommesse>monete){
                cout << "Il numero di monete scommesse supera quelle attuali, riprova..." << endl;
                sleep(1);
                cout << "quante monete vuoi scommettere?" << endl;
                cin >> monetescommesse;
            }
        }
        if (gioco == 1) {
            pgiocate++;
            cout << "Tentativi disponibili: 20" << endl;
            cout << numero_da_indovinare << endl;
            cout << "indovina il numero che ho pensato: ";
            cin >> tentativo;
            cout << endl;

            for (int i = 0; i < 20; ++i) {

                srand(time(NULL));

                modifica = rand() % 3 + 3;


                if (tentativo > numero_da_indovinare) {

                    cout << "il numero è troppo grande" << endl;

                    numero_da_indovinare -= modifica;

                } else if (tentativo < numero_da_indovinare) {

                    cout << "il numero è troppo piccolo" << endl;

                    numero_da_indovinare += modifica;
                } else {
                    cout << "Bravo :D , hai indovinato il numero" << endl;
                    cout << endl;
                    pvinte++;
                    monete += monetescommesse;                    //modifica (add) monete e pvinte
                    sleep(2);
                    break;
                }

                cout << "tentaviri rimanenti: " << 20 - i << endl;

                cout << "--------------------------------" << endl;
                sleep(1);
                cout << "indovina il numero che ho pensato: ";
                cin >> tentativo;
            }
            if (tentativo != numero_da_indovinare){
                cout << "Hai perso, la prossima volta sarai più fortunato" << endl;
                monete -= monetescommesse;
                sleep(2);

            }

        } else if (gioco == 2) {
            cout << "non ho voglia di programmare il blackjack :C " << endl;
        }

#ifdef _WIN32                       //clear terminale al termine di ogni gioco (sia per windows che per linux)
        system("cls");
#endif
#ifdef linux
        system("clear");
#endif
        cout << endl;



    }

    return 0;
}
