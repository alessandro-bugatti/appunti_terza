#include <iostream>
#include <cmath>

struct Punto{
    //Rappresenta l'ascissa
    float x;
    //Rappresenta l'ordinata
    float y;
};

struct Triangolo{
    Punto a;
    Punto b;
    Punto c;
};

const int MAX_PUNTI = 100;

struct Spezzata{
    Punto punti[MAX_PUNTI];
    int n_punti;
};

/**
 * Stampa un Punto a video
 * @param p Punto da stampare
 */
void stampa_punto(const Punto &p){
    std::cout << "x = " << p.x << " , y = " << p.y << std::endl;
}

/**
 * Calcola la distanza tra due punti
 * @return
 */
float distanza(const Punto &p1, const Punto &p2){
    float d;
    d = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
    return d;
}

/**
 * Calcola il punto medio
 * @return
 */
Punto punto_medio(const Punto &p1, const Punto &p2){
    Punto m;
    m.x = (p1.x + p2.x)/2;
    m.y = (p1.x + p2.y)/2;
    return m;
}

float calcola_perimetro(const Triangolo &t){
    return distanza(t.a, t.b) + distanza(t.b, t.c) +
            distanza(t.c, t.a);
}

/**
 * Calcola la lunghezza di una spezzata
 * @return
 */
float lunghezza(const Spezzata &s){
    float totale = 0;
    for (int i = 0; i < s.n_punti - 1; ++i) {
        totale += distanza(s.punti[i], s.punti[i+1]);
    }
    return totale;
}

int main() {
    //Dichiarazione
    Punto p, r;
    //Assegnamento
    p.x = 3.4;
    p.y = -5.67;
    //Assegnamento compatto
    r = {2.3, 6.7};
    //Input/output
    stampa_punto(p);
    stampa_punto(r);
    std::cout << "Inserisci la coordinata x del punto: ";
    std::cin >> p.x;
    std::cout << "Inserisci la coordinata y del punto: ";
    std::cin >> p.y;
    std::cout << "(" << p.x << " , " << p.y << ")" << std::endl;
    stampa_punto(p);
    std::cout << distanza(p, r) << std::endl;
    Punto m = punto_medio(p, r);
    stampa_punto(punto_medio(p, m));
    std::cout << (punto_medio(p,r)).x << std::endl;
    std::cout << (punto_medio(p,r)).y << std::endl;

    //Creo una spezzata con punti casuali
    Spezzata s;
    int quanti;
    std::cout << "QUanti punti vuoi che abbia la spezzata: ";
    std::cin >> quanti;
    for (int i = 0; i < quanti; ++i) {
        s.punti[i].x = rand()%500;
        s.punti[i].y = rand()%500;
    }
    s.n_punti = quanti;
    return 0;
}
