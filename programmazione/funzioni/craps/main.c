#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lanciadado(void) {
    return rand()%6+1;
}
int lancio2dadi(void) {
    return lanciadado()+lanciadado();
}
int lancia_dado_n_facce(int n) {
    return rand()%n+1;
}
int main(void) {
  srand(time(NULL));
    int lancio, target;
    printf("gioco del craps\n");
    lancio=lancio2dadi();
    printf("al primo lancio è uscito %d\n" ,lancio);
    if(lancio==7 || lancio==11) {
        printf("hai vinto \n");
    }
    else if(lancio==2 || lancio==3 || lancio==12) {
        printf("hai perso \n");
    }
    else {
        target=lancio;
        do {
            lancio=lancio2dadi();
            printf("è uscito il valore %d\n",lancio);

        }while(lancio!=target && lancio!=7);
        if(lancio==target) {
            printf("hai vinto" );

        }
        else {
            printf("hai perso");
        }
    }
    return 0;
}
