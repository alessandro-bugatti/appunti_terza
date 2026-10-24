#include <iostream>

int main() {
    int tiro_pc, tiro_giocatore,scelta,continua,vittorie=0,sconfitte=0;
    bool pari;
    srand(time(NULL));
    do {
        std::cout<<"vuoi fare pari (1) oppure dispari (2) :"<<std::endl;
        std::cin>>scelta;
        if (scelta == 1) {
            pari=true;
        }
        else {
            pari=false;
        }
        std::cout<<"che numero vuoi tirare? ";
        std::cin>>tiro_giocatore;
        tiro_pc=rand() % 6;
        if (pari && (tiro_pc+tiro_giocatore)% 2 == 0 ||
            !pari && (tiro_pc+tiro_giocatore)% 2 == 1) {
            std::cout<<"hai vinto perchè il computer ha tirato:"<<tiro_pc<<std::endl;
            vittorie++;
            }
        else {
            std::cout<<"hai perso perchè il computer ha tirato:"<<tiro_pc<<std::endl;
            sconfitte++;
        }
        std::cout<<"hai vinto: "<<vittorie<<" volte e hai perso: "
            <<sconfitte<<" volte." << std::endl;

        std::cout<<"vuoi fare un'altra partita? (1) per continuare (0) per uscire :";
        std::cin>>continua;
    }while (continua != 0);


    return 0;
}
