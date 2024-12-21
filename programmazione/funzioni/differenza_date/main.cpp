#include <iostream>

bool bisestile(int a) {
    return a % 400 == 0 || !(a % 100 == 0) && a % 4 == 0;
}

int giorni_nel_mese(int m, int a) {
    if (m == 2) {
        if (bisestile(a)) {
            return 29;
        }
        return 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    return 31;
}

int giorni_mesi(int m, int a) {
    int totale = 0;
    for (int i = 1; i < m; ++i) {
        totale += giorni_nel_mese(i, a);
    }
    return totale;
}

int giorni_anni(int a) {
    int totale = 0;
    for (int i = 1900; i < a; ++i) {
        if (bisestile(i)) {
            totale += 366;
        }
        else {
            totale += 365;
        }
    }
    return totale;
}

int trasforma_in_giorni(int g, int m, int a) {
    return giorni_anni(a) + giorni_mesi(m, a) + g;
}

int differenza_date(int g1, int m1, int a1,
                    int g2, int m2, int a2) {
    int n1 = trasforma_in_giorni(g1, m1, a1);
    int n2 = trasforma_in_giorni(g2, m2, a2);
    return n2 - n1;
}

int main() {
    std::cout << differenza_date(1, 1, 2020, 21, 12, 2024) << std::endl;
    return 0;
}