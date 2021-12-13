#include <iostream>

int bisestile(int anno)
{
    if (anno % 400) return 1;
    //....
}

int giorni_nel_mese(int mese, int anno)
{
    switch(mese){
        case 2:
            return 28 + bisestile(anno);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        default:
            return 31;
    }
}

int converti_in_giorni(int g, int m, int a)
{
    int giorni = g;
    for (int i = 1; i < m; i++)
    {
        giorni += giorni_nel_mese(i, a);
    }
    return giorni;
}

int differenza(int g1, int m1, int a1, int g2, int m2, int a2)
{
    return converti_in_giorni(g2,m2,a2) - converti_in_giorni(g1, m1, a1);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}