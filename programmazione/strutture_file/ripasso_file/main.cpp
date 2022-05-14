#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt"), in2("input2.txt");
    //Controllo se ci sono stati problemi
    if (!in || !in2)
    {
        cout << "Problemi con l'apertura del file" << endl;
        return 1;
    }
    float n, n2, media = 0;
    int conta = 0;
    string riga;
    //Primo modo per leggere tutti i valori in un file
    //va bene se si sa come è strutturato e i dati sono semplici
    while(in >> n)
    {
        media += n;
        conta++;
    }
    //Secondo modo, più generale, legge tutto il file riga per riga
    //e poi si fa quello che si vuole della riga letta
    while(getline(in2, riga))
    {
        float temp = stof(riga);
        media += temp;
        conta++;
    }
    in.close();
    in2.close();
    //cout << media/conta << endl;
    ofstream out("media.txt");
    if (!out)
    {
        cout<< "Non posso scrivere il risultato" << endl;
        return 1;
    }
    out << "I file contengono " << conta << " valori" << endl;
    out << media/conta << endl;
    out.close();
    return 0;
}
