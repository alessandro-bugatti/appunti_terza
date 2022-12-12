#include <iostream>

bool primo(int n){
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) //il numero n è divisibile per i?
        {
            return false;
        }
    }
    return true;
}

/**
 * Conta quanti numeri primi sono compresi nell'intervallo [inizio, fine)
 * @param inizio primo numero da testare
 * @param fine estremo superiore dell'intervallo non incluso
 * @return Quanti numeri primi sono compresi in [inizio, fine)
 */
int conta_primi(int inizio, int fine){
    int conta = 0;
    for (int i = inizio; i < fine; ++i) {
        if (primo(i))
        {
            conta++;
        }
    }
    return conta;
}

int main() {
    int n, conta = 0;
    std::cout << "Inserisci un valore di n: " << std::endl;
    std::cin >> n;
    for (int i = 2; i <= n; ++i) {
        if(primo(i)){
            std::cout << i << std::endl;
            conta++;
        }

    }
    std::cout << "I numeri primi minori o uguali a " << n << " sono " << conta
    << std::endl;

    for (int i = 0; i < 1000; ++i) {
        int inizio = 1 + 100*i;
        int fine = 100 + 100*i;
        std::cout << "Ci sono "<< conta_primi(inizio, fine) <<
        " numeri primi compresi tra "<< inizio << " e "
        << fine << std::endl;
    }

    return 0;
}
