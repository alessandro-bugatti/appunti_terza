#include <iostream>

int main()
{
    int n_ore;
    float paga,totale;
    totale=0;
    std::cout << "inserisci numero ore";
    std::cin >> n_ore;
    while (n_ore>-1)
    {
        if (n_ore>40)
        {
            paga=32.5*(n_ore-40)+(40*22);
        }
        else
        {
            paga=22*n_ore;
        }
        std::cout << "la paga è" <<paga;
        totale+=paga;
        std::cout << "inserisci numero ore";
        std::cin >> n_ore;
    }
    std::cout << "il totale pagato è:" << totale;
    return 0;
}