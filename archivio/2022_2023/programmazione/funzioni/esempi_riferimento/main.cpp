#include <iostream>
#include <valarray>

void scambia(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void somma(int &a, int b){
    a += b;
}

int somma2(int a, int b){
    return a + b;
}

float delta(float a, float b, float c){
    return b*b - 4*a*c;
}

/**
 * Funzione per il calcolo delle radici di un'eq. di secondo grado
 * @param a Coefficiente di secondo grado
 * @param b Coefficiente di primo grado
 * @param c Coefficiente di grado zero
 * @param x1 Prima soluzione
 * @param x2 Seconda soluzione
 */
void secondo_grado(float a, float b, float c, float &x1, float &x2){
    x1 = (-b + sqrt(delta(a,b,c))) / (2 * a);
    x2 = (-b - sqrt(delta(a,b,c))) / (2 * a);
}

bool secondo_grado2(float a, float b, float c, float &x1, float &x2){
    if (delta(a,b,c) < 0){
        return false;
    }
    x1 = (-b + sqrt(delta(a,b,c))) / (2 * a);
    x2 = (-b - sqrt(delta(a,b,c))) / (2 * a);
    return true;
}



int main() {
    //int c = 3, d = 7;
    //scambia(c, d);
    //somma(c, d);
    //c = somma2(c, d);
    //std::cout << c << std::endl;
    float a = 3, b = 100, c = 7;
    float x1, x2;
    if (secondo_grado2(a, b, c, x1, x2) == true){
        std::cout << "x1 = " << x1 << " x2 = " << x2 << std::endl;
    }
    else
    {
        std::cout << "Non ha soluzioni nel campo dei reali" << std::endl;
    }
    return 0;
}
