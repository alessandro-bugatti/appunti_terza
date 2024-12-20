#include <iostream>

int giorni_nel_mese(int m, int a) {

}

int giorni_mesi(int m, int a) {
    int totale = 0;
    for (int i = 1; i < m; ++i) {
        totale += giorni_nel_mese(m, a);
    }
    return totale;
}

bool bisestile(int a) {

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

    return 0;
}