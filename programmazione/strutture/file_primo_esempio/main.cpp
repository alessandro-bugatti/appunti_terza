#include <iostream>
#include <fstream>

int main() {
    //Per utilizzare i file si passa sempre attraverso tre operazioni

    //1) Apertura in lettura (equivalente a cin) o in scrittura (cout)
    //Esempio in lettura

    std::ifstream in("../dati.txt");  //Apertura di un file in lettura

    if(!in){
        std::cout << "Apertura fallita" << std::endl;
        return 1;
    }
    //2) parte lettura vera e propria
    int n;
    in >> n;
    std::cout << n << std::endl;

    //3) chiusura del file
    in.close();

    //Esempio di lettura di un file contenente esattamente 2 numeri interi
    int n1, n2;
    std::ifstream in2("../dati2.txt");
    if(!in2){
        std::cout << "Apertura fallita" << std::endl;
        return 1;
    }
    in2 >> n1;
    in2 >> n2;

    std::cout << "Il prodotto dei due numeri vale " << n1*n2 << std::endl;
    in2.close();

    std::ifstream in3("../dati3.txt");
    if (!in3){
        std::cout << "Apertura fallita" << std::endl;
        return 1;
    }
    int numero;
    std::string stringa;

    in3 >> numero >> stringa;

    for (int i = 0; i < numero; ++i) {
        std::cout << stringa << std::endl;
    }
    in3.close();

    //Esempio con tanti valori
    //PRima versione: all'inizio del file c'è scritto quanti sono
    int N, temp;
    std::ifstream in4("../elenco_con_n.txt");
    if (!in4){
        std::cout << "Apertura fallita" << std::endl;
        return 1;
    }
    in4 >> N;
    for (int i = 0; i < N; ++i) {
        in4 >> temp;
        std::cout << temp << std::endl;
    }
    //Seconda versione: leggi finchè ce ne sono
    std::ifstream in5("../elenco.txt");
    if (!in5){
        std::cout << "Apertura fallita" << std::endl;
        return 1;
    }
    float valore;
    while(in5 >> valore){
        std::cout << valore << std::endl;
    }
    in5.close();
    return 0;
}
