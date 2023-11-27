#include <iostream>
/**
 * funzione che ritorna un numero casuale compreso tra a e b inclusi
 * @param a estremo inferiore
 * @param b estremo superiore
 * @return numero casuale tra a e b
 */

int random (int a, int b) {
    int numerocasuale=rand()%(b-a+1)+a;
    return numerocasuale;
}

int lancio_dadi(int facce, int n_dadi){
    int risultato = 0;
    for (int i = 0; i < n_dadi; ++i) {
        risultato+= random(1,facce);
    }
    return risultato;
}

/**
 * funzione che simula il lancio di una dado a 6 facce
 * @return un numero compreso da 1 e 6
 */
int un_dado(){
    return random(1,6);
}
int due_dadi (){
    return un_dado()+un_dado();
}

int main() {
    std::cout << random(5,12)<< std::endl;
    std::cout << un_dado()<< std::endl;
    std::cout << due_dadi() << std::endl;
    std::cout << lancio_dadi(10,3) << std::endl;
    //Piccolo test per verificare gli estremi della funzione lancio_dadi
    int facce = 12, n_dadi = 5;
    for (int i = 0; i < 1000000; ++i) {
        int risultato = lancio_dadi(facce,n_dadi);
        if (risultato < n_dadi || risultato > facce*n_dadi) {
            std::cout << "Errore: al lancio " << i+1 << std::endl;
        }
    }
    return 0;
}
