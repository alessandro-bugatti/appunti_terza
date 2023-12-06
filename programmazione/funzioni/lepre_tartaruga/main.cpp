#include <iostream>

void muovi_tartaruga (int &posizione){
    int n;
    n=rand()%100+1;
    if (n<=50){
        posizione+=3;
    } else if (n<=70){
        posizione-=6;
    } else {
        posizione++;
    }
}

void disegna_tartaruga (int posizione){
    for (int i = 0; i <= posizione; ++i){
        std::cout << " ";
    }
    std::cout << "t" << std::endl;
}

int main() {
    const int LUNGHEZZA=60;
    int pos_tartaruga=0, pos_lepre=0;
    for (int i = 0; i < 5; ++i) {
        muovi_tartaruga(pos_tartaruga);
        std::cout << pos_tartaruga << std::endl;
    }
    while (pos_tartaruga<=LUNGHEZZA and pos_lepre<=LUNGHEZZA){

    }

    return 0;
}
