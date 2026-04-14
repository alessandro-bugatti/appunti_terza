# Gioco Indovina la parola

## Analisi delle funzionalità

Sono state individuate le seguenti funzionalità

1. contatore degli errori (A)
2. estrazione parola casuale (B)
3. controllo sul raggiungimento del numero massimo di errori (C)
4. sostituzione delle lettere corrette (A)
5. controllo se la parola è stata indovinata (B)
6. input del giocatore (C)
7. controllo della correttezza dell'input (A)
8. reset del gioco per un'altra partita (C)
9. elenco delle lettere già uscite (A)
 
## Implementazione delle funzionalità come funzioni C++

1. contatore degli errori (A)
   Non serve una funzione, basta un contatore
2. estrazione parola casuale (B)
   ```c++
   string estrai(); // B
   ```
3. controllo sul raggiungimento del numero massimo di errori (C)
   Non  serve una funzione, basta un <
4. sostituzione delle lettere corrette (A)
    ```c++
    void sostituisci(string &parola, char lettera, const string &segreta); // C
    ```
5. controllo se la parola è stata indovinata (B)
   ```c++
   bool indovinata(const string &parola, const string &segreta); // A
   ``` 
6. input del giocatore (C)
   
   Viene gestito nel main direttamente
7. controllo della correttezza dell'input (A)
    ```c++
   bool lettera_corretta(char c); // B
   ```
8. reset del gioco per un'altra partita (C)
    ```c++
   void reset(string &parola, string &segreta, string &uscite, int &n_errori); // C
    ```
9. elenco delle lettere già uscite (A)
    ```c++
   void lettere_uscite(string &uscite, char c); // C
    ```
    