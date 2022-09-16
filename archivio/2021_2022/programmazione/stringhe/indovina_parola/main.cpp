 #include <iostream>

using namespace std;

string inizializza(string s)
{
    string t;
    for (int i = 0; i < s.size(); ++i) {
        t += '_';
    }
    return t;
}


/**
 * Inserisce la lettera, se indovinata, nelle posizioni corrette all'interno
 * della stringa corrente
 * @param segreta
 * @param corrente
 * @param lettera
 */
bool controlla_parola(string segreta, string &corrente, char lettera){
    bool trovata = false;
    for (int i = 0; i < segreta.size(); ++i) {
         if (segreta.at(i) == lettera) {
             corrente.at(i) = lettera;
            trovata = true;
         }
     }
    return trovata;
}

int main() {
    const int MAX_ERRORI = 7;
    bool indovinata = false;
    int errori = 0;
    //Qua sarà da sostituire con l'input del primo giocatore
    string segreta = "tavolata";
    string corrente = inizializza(segreta);
    string lettere_provate;
    while (!indovinata && errori < MAX_ERRORI){
        //Visualizzazione
        cout << corrente << endl;
        cout << "Finora hai fatto : " << errori << " errori" << endl;
        cout << " e hai provato le seguenti lettere: " << lettere_provate << endl;
        //Input
        cout << "Proponi una lettera: ";
        char lettera;
        cin >> lettera;
        lettere_provate += lettera;
        lettere_provate += ',';
        //Controllo
        bool trovata = controlla_parola(segreta, corrente, lettera);
        if (!trovata){
            errori++;
            cout << "Ahi ahi ahi, hai sbagliato" << endl;
        }
        if (segreta == corrente)
            indovinata = true;

    }

    return 0;
}
