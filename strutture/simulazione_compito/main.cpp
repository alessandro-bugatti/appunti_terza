#include <iostream>
#include <vector>

void rimuovi_spazi(std::string &s) {
    int pos = 0;
    /*
    while (s.at(0) == ' ') {
        s.erase(0, 1);
    }
    */
    while (s.at(pos) == ' ') {
        pos++;
    }
    s.erase(0, pos);
    pos = s.size() - 1;
    while (s.at(pos) == ' ') {
        pos--;
    }
    s.erase(pos);
}

void rimuovi_occorrenze(std::string &s1, const std::string &s2) {
    int pos = 0;
    while ((pos = s1.find(s2, pos)) != std::string::npos) {
        s1.erase(pos, s2.size());
    }
}

struct Razionale
{
    int numeratore;
    int denominatore;
};

int MCD(int a, int b) {
    if (b > a ) {
        int temp = a;
        a = b;
        b = temp;
    }
    int i = b;
    while (i > 0) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
}

Razionale somma(const Razionale &a, const Razionale &b) {
    Razionale ris;
    ris.denominatore = a.denominatore * b.denominatore;
    ris.numeratore = a.numeratore * b.denominatore + b.numeratore *
        a.denominatore;
    int m = MCD(ris.numeratore, ris.denominatore);
    ris.numeratore /= m;
    ris.denominatore /= m;
    return ris;
}

struct Data
{
    int g, m, a;
};

struct ContoCorrente
{
    std::string numero;
    Data apertura;
    float saldo;
};

float calcola_media(const std::vector<ContoCorrente> &conti, int anno) {
    int n = 0;
    float media = 0;
    for (int i = 0; i < conti.size(); ++i) {
        if (conti.at(i).apertura.a == anno) {
            media += conti.at(i).saldo;
            n++;
        }
    }
    if (n == 0) {
        return -1;
    }
    return media / n;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
