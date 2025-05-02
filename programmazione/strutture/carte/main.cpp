#include <iostream>
#include <vector>

struct Carta {
    int seme;
    int valore;
};

std::string nome_carta(const Carta& c) {
    std::string s;
    if (c.valore <= 10) {
        s = std::to_string(c.valore);
    }
    else if (c.valore == 11){
        s = "Fante";
    }
    else if (c.valore == 12) {
        s = "Donna";
    }
    else {
        s = "Re";
    }
    s += " di ";
    if (c.seme == 1) {
        s += "Cuori";
    }
    else if (c.seme == 2) {
        s += "Quadri";
    }
    else if (c.seme == 3) {
        s += "Fiori";
    }
    else {
        s += "Picche";
    }
    return s;
}

std::vector<Carta> crea_mazzo() {
    std::vector<Carta> m;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 13; ++j) {
            Carta c;
            c.seme = i;
            c.valore = j;
            m.push_back(c);
        }
    }
    return m;
}

void mescola_mazzo(std::vector<Carta>& m) {
    Carta temp;
    int a, b;
    for (int i = 0; i < 10 * m.size(); ++i) {
        a = rand() % m.size();
        b = rand() % m.size();
        temp = m.at(a);
        m.at(a) = m.at(b);
        m.at(b) = temp;
    }
}

Carta pesca_carta(std::vector<Carta>& m) {
    Carta c = m.at(m.size() - 1);
    m.pop_back();
    return c;
}

int conta_punti(const std::vector<Carta>& mano) {
    int somma = 0;
    for (int i = 0; i < mano.size(); ++i) {
        int valore = mano.at(i).valore;
        if (valore <= 10) {
            somma += valore;
        }
        else {
            somma += 10;
        }
    }
    return somma;
}

int main() {
    srand(time(NULL));
    // Carta c, d;
    // //Assegnamento
    // c.seme = 1;
    // c.valore = 7;
    // //Input
    // /*std::cout << "Inserisci il seme (1 - cuori, 2 - quadri, 3- fiori, 4 - picche): ";
    // std::cin >> d.seme;
    // std::cout << "Inserisci il valore: ";
    // std::cin >> d.valore;*/
    // //Output
    // std::cout << nome_carta(c) << std::endl;
    // std::cout << nome_carta(d) << std::endl;
    // //creazione del mazzo di carte
    // std::vector<Carta> mazzo;
    // mazzo = crea_mazzo();
    // for (int i = 0; i < mazzo.size(); ++i) {
    //     std::cout << nome_carta(mazzo.at(i)) << std::endl;
    // }
    // mescola_mazzo(mazzo);
    // for (int i = 0; i < mazzo.size(); ++i) {
    //     std::cout << nome_carta(mazzo.at(i)) << std::endl;
    // }
    // std::vector<Carta> mano;
    // for (int i = 0; i < 5; ++i) {
    //     Carta c = pesca_carta(mazzo);
    //     mano.push_back(c);
    // }
    // std::cout << "Mano del giocatore" << std::endl;
    // for (int i = 0; i < mano.size(); ++i) {
    //     std::cout << nome_carta(mano.at(i)) << std::endl;
    // }
    // std::cout << "Valore della mano attuale: " << conta_punti(mano) << std::endl;

    return 0;
}