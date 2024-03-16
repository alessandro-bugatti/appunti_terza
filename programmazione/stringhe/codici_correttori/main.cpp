#include <iostream>

/**
 * Aggiunge il bit di parità a una stringa di lunghezza qualsiasi
 * @param s La stringa a cui aggiungere il bit di parità, viene
 * modificata dalla funzione
 */
void aggiungi_parita(std::string &s){
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s.at(i) == '1'){
            count++;
        }
    }
    if (count % 2 == 0){
        s += '0';
    }
    else{
        s += '1';
    }
}

/**
 * Funzione con lo stesso scopo della funzione precedente
 * stavolta ritorna il bit di parità, 0 o 1, e non modifica
 * la stringa passata come parametro
 * @param s stringa su cui calcolare il bit di parità
 * @return il bit di parità, sotto forma di intero, 0 o 1
 */
int bit_parita(const std::string &s){
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s.at(i) == '1'){
            count++;
        }
    }
    return  count % 2;
}

/**
 * Funzione che corregge una stringa di esattamente 7 bit
 * usando un codice di Hammming (7,4)
 * @param s La stringa che eventualmente deve essere corretta
 * Se non ci sono errori la stringa rimarrà inalterata
 */
void hamming_7_4(std::string &s){
    std::string risultato;
    int passo = 1;
    //Per ogni bit di parità viene calcolata la parità
    //e concatenata nella stringa risultato
    for (int i = 0; i < 3; ++i) {
        int count = 0; //Contatore degli 1
        int j = 0;
        //Ciclo che somma solo i bit nelle posizioni indicate da passo
        while (j < s.size()) {
            for (int k = 0; k < passo; ++k) {
                if (s.at(s.size() - 1 - j) == '1'){
                    count++;
                }
                j++;
            }
            j += passo;
        }
        //Verifica se il numero di 1 è pari o dispari e accoda il
        //valore opportuno alla stringa risultato
        if (count % 2 == 0)
            risultato += '0';
        else
            risultato += '1';
        //Il passo viene raddoppiato per il prossimo giro
        passo *= 2;
    }
    //Traduzione del risultato come numero binario,
    //considerando che le cifre sono invertite
    int posizione = 0;
    int potenza = 1;
    for (int i = 0; i < risultato.size(); ++i) {
        if (risultato.at(i) == '1')
            posizione += potenza;
        potenza *= 2;
    }
    //Non ci sono errori
    if (posizione == 0)
        return;
    //Viene corretto l'errore in posizione, invertendo il bit
    if (s.at(posizione) == '1')
        s.at(posizione) = '0';
    else
        s.at(posizione) = '1';
}

/**
 * Funzione che corregge una stringa di un numero qualsiasi di bit
 * usando un codice di Hammming (n,m), dove n è il numero
 * di bit della stringa e m è il logaritmo in base 2 di n
 * Come si può vedere, l'unica differenza rispetto alla funzione precedente
 * è che il numero di bit di parità non è più fisso a 3,
 * ma dipende dalla lunghezza della parola, utilizzando il logaritmo in base 2
 * @param s La stringa che eventualmente deve essere corretta
 * Se non ci sono errori la stringa rimarrà inalterata
 */
void hamming(std::string &s){
    std::string risultato;
    int passo = 1;
    //Calcolo del logaritmo in base 2 di n usando divisioni
    //successive
    int m, n = s.size();
    while(n > 0){
        n /= 2;
        m++;
    }
    //Per ogni bit di parità viene calcolata la parità
    //e concatenata nella stringa risultato

    for (int i = 0; i < m; ++i) {
        int count = 0; //Contatore degli 1
        int j = 0;
        //Ciclo che somma solo i bit nelle posizioni indicate da passo
        while (j < s.size()) {
            for (int k = 0; k < passo; ++k) {
                if (s.at(s.size() - 1 - j) == '1'){
                    count++;
                }
                j++;
            }
            j += passo;
        }
        //Verifica se il numero di 1 è pari o dispari e accoda il
        //valore opportuno alla stringa risultato
        if (count % 2 == 0)
            risultato += '0';
        else
            risultato += '1';
        //Il passo viene raddoppiato per il prossimo giro
        passo *= 2;
    }
    //Traduzione del risultato come numero binario,
    //considerando che le cifre sono invertite
    int posizione = 0;
    int potenza = 1;
    for (int i = 0; i < risultato.size(); ++i) {
        if (risultato.at(i) == '1')
            posizione += potenza;
        potenza *= 2;
    }
    //Non ci sono errori
    if (posizione == 0)
        return;
    //Viene corretto l'errore in posizione, invertendo il bit
    if (s.at(posizione) == '1')
        s.at(posizione) = '0';
    else
        s.at(posizione) = '1';
}


int main() {
    std::string a = "01110010", b = "11000111";
    aggiungi_parita(a);
    aggiungi_parita(b);
    std::cout << a << " " << b << std::endl;
    std::string s;
    std::cout << "Inserisci la stringa codificata con Hamming: ";
    std::cin >> s;
    std::cout << "Stringa prima della correzione: " + s << std::endl;
    hamming(s);
    std::cout << "Stringa dopo la correzione: " + s << std::endl;
    return 0;
}
