#include <iostream>
#include <vector>

struct Gita{
    std::string nome;
    std::vector<std::string> tappe;
};

Gita gita_con_piu_tappe(const std::vector<Gita> &gite) {
    Gita g;
    g = gite.at(0);
    for (int i = 1; i < gite.size(); ++i) {
        if (gite.at(i).tappe.size() > g.tappe.size()) {
            g = gite.at(i);
        }
    }
    return g;
}

bool cerca_tappa(const Gita &g, const std::string &tappa) {
    for (int i = 0; i < g.tappe.size(); ++i) {
        if (g.tappe.at(i) == tappa) {
            return true;
        }
    }
    return false;
}

std::vector<Gita> gite_con_tappa_richiesta(
    const std::vector<Gita> &gite,
    const std::string &tappa) {
    std::vector<Gita> trovate;
    for (int i = 0; i < gite.size(); ++i) {
        if (cerca_tappa(gite.at(i), tappa) == true) {
            trovate.push_back(gite.at(i));
        }
    }
    return trovate;

}

void stampa(const Gita &g) {
    std::cout << g.nome << std::endl;
    std::cout << "Questa gita ha " << g.tappe.size() << std::endl;
    for (int i = 0; i < g.tappe.size(); ++i) {
        std::cout << i + 1 << "ª tappa: " <<
            g.tappe.at(i) << std::endl;
    }
}

int main() {
    std::vector<Gita> gite;
    Gita g;
    g.nome = "Giro tra i monti del Trentino";
    g.tappe.push_back("Brescia");
    g.tappe.push_back("Trento");
    g.tappe.push_back("Affi");
    g.tappe.push_back("Brescia");
    gite.push_back(g);
    g.nome = "Lago di Garda e dintorni";
    g.tappe.clear();
    g.tappe.push_back("Brescia");
    g.tappe.push_back("Salò");
    g.tappe.push_back("Gardone");
    g.tappe.push_back("Riva");
    g.tappe.push_back("Brescia");
    gite.push_back(g);
    std::cout << "Sono state inserite " <<
        gite.size() << " gite." << std::endl;
    g  = gita_con_piu_tappe(gite);
    stampa(g);
    stampa(gite.at(0));//Verifica che non abbiamo perso le tappe della prima gita in seguito alla chiamata di clear
    return 0;
}
