#include <iostream>
#include <fstream>

int main() {
    //Per utilizzare i file si passa sempre attraverso tre operazioni

    //1) Apertura in lettura (equivalente a cin) o in scrittura (cout)
    //Esempio in lettura

    std::ifstream in("dati.txt");  //Apertura di un file in lettura

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


    return 0;
}
