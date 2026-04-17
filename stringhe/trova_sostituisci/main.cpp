#include <iostream>

int main() {
    std::string s = "Gli esercizi sulle query qui contenuti utilizzano il database World, fornito con le versione di MySQL dei primi anni 2000, come strumento per fare pratica anche per le certificazioni di MySQL. I tre PDF di descrizione indicano i nomi dei campi delle tabelle e le loro relazioni, ci sono poi degli esercizi con relative soluzioni e infine il database vero e proprio, da scaricare e installare in locale per provare a fare gli esercizi.";

    std::string cercata, nuova;
    int pos;
    std::cout << "Dimmi la parola da sostituire: ";
    std::cin >> cercata;
    std::cout << "Dimma la nuova parola: ";
    std::cin >> nuova;
    while ((pos = s.find(cercata)) != std::string::npos) {
        s.replace(pos, cercata.size(), nuova);
    }
    std::cout << s << std::endl;
    return 0;
}
