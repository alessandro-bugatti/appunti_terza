#include <iostream>

/**
 * la funzione permette di trovare il numero maggiore fra due numeri
 * @param a primo numero
 * @param b secondo numero
 * @return  il maggiore fra a e b
 */

int maggiore(int a,int b){
    int max;
    if (a>b){
        max = a;
    }else{
        max = b;
    }
    return max;
}

int main() {
    int c,d,e,f;
    c=7;
    d=8;
    f=9;
    e = maggiore(c,maggiore(d,f));
    std::cout<<e<<std::endl;
    return 0;
}
