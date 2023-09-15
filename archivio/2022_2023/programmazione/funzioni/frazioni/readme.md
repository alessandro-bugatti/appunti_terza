# Operazioni tra frazioni

Si scrivano le seguenti funzioni che, date due frazioni nella forma di coppie numeratore/denominatore, 
calcolino il risultato dell'operazione specificata. 
Le funzioni dovranno inserire il risultato in ulteriori due parametri passati per riferimento.
- **somma**: fa la somma tra due frazioni
- **differenza**: fa la differenza tra due frazioni
- **prodotto**: fa il prodotto tra due frazioni
- **divisione**: fa la divisione tra due frazioni

Fare poi due funzioni di supporto con il seguente scopo:
- **semplifica**: ricevuti come parametri numeratore e denominatore di una funzione, riduce la frazione ai minimi termini. Se ad esempio il numeratore valesse 15 e il denominatore 21, dopo la chiamata di questa funzione diventerebbero rispettivamente 5 e 7.
- **stampa**: stampa la funzione nella forma n/d. Se ad esempio il numeratore valesse 3 e il denominatore 7, la funzione stamperebbe 3/7. Attenzione ai casi particolari, che vanno stampati nel modo solito della matematica, quindi:
  - numeratore = 3 denominatore = 1 deve essere stampato come 3, **non** come 3/1
  - numeratore = 3 denominatore = -4 deve essere stampato come -3/4, **non** come 3/-4
  - numeratore = -3 denominatore = -4 deve essere stampato come 3/4, **non** come -3/-4
  - numeratore = 0 denominatore = 4 deve essere stampato come 0, **non** come 0/4

Si può supporre che il denominatore sia sempre diverso da zero, oppure fare dei controlli che impediscano l'inserimento dello zero come valore per il denominatore.

Si scriva successivamente un programma a menù che permetta di fare le quattro operazioni tra frazioni, sfruttando le funzioni descritte in precedenza, con i valori delle frazioni inseriti dall'utente. Il programma deve permettere di fare operazioni fino a quando l'utente desidera. Viene lasciata libertà nei dettagli, la cosa importante è che si cerchi di organizzarlo nel modo più ordinato possibile.
