#include <iostream>
#include <thread>
#include <valarray>

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
    if (posizione < 0)
        posizione = 0;
}

void muovi_lepre (int &posizione){
    int n;
    n = rand()%100+1;
    if (n<=20){
        posizione+=9;
    } else if (n<=30){
        posizione-=12;
    } else if (n<=60) {
        posizione += 1;
    } else if (n <= 80){
        posizione -= 2;
    }
    //Per il 20% non fa nulla, dorme
    if (posizione < 0 )
        posizione = 0;
}

void disegna_tartaruga (int posizione){
    for (int i = 0; i <= posizione; ++i){
        std::cout << " ";
    }
    std::cout << "T" << std::endl;
}

void disegna_lepre (int posizione){
    for (int i = 0; i <= posizione; ++i){
        std::cout << " ";
    }
    std::cout << "L" << std::endl;
}

void ritardo_with_cpu()
{
    double a = 0;
    for (int i = 0; i < 100000000; ++i) {
        a += sqrt(i);
    }
}

void ritardo_no_cpu()
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(500ms);
}

int main() {
    const int LUNGHEZZA=60;
    int pos_tartaruga=0, pos_lepre=0;
    /* for (int i = 0; i < 5; ++i) {
        muovi_tartaruga(pos_tartaruga);
        std::cout << pos_tartaruga << std::endl;
    }*/

    while (pos_tartaruga<=LUNGHEZZA && pos_lepre<=LUNGHEZZA){
        system("cls");
        disegna_lepre(pos_lepre);
        disegna_tartaruga(pos_tartaruga);
        ritardo_no_cpu();
        //ritardo_with_cpu();
        muovi_lepre(pos_lepre);
        muovi_tartaruga(pos_tartaruga);
    }
    if (pos_lepre > pos_tartaruga)
        std::cout << "Ha vinto la lepre " << std::endl;
    else
        std::cout << "Ha vinto la tartaruga " << std::endl;
    return 0;
}
