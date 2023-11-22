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
    return 0;
}
