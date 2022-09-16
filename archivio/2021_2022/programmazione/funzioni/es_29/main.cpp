#include <iostream>

int converti_in_giorni(int g, int m, int a)
{
    int giorni = (a-1)*360 + \(m-1)*30 + g;
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
