## Esercizio del parcheggio

Un garage fa pagare una tariffa minima di 2,00 euro per parcheggiare fino a tre ore, più 0.50 all'ora per ogni ora o parte di essa oltre le tre ore. Il costo massimo per un periodo di 24 ore è di 10,00 euro. Supponete che nessuna macchina resti parcheggiata per più di 24 ore. 

Scrivete un programma che calcoli e stampi i costi del parcheggio per ciascuno degli N clienti che ieri hanno parcheggiato le loro auto in questo garage. 

## Versione semplice

Dovete inserire le ore di parcheggio per ogni cliente. Il vostro programma deve stampare i risultati in un formato tabellare e deve calcolare e stampare il totale degli incassi di ieri. Il programma deve usare la funzione *calcolaCosti* per determinare il costo per ogni cliente. Decidere in maniera autonoma quali saranno i parametri e l'eventuale valore di ritorno della funzione. 

L'output finale deve avere un formato simile a questo:

| Macchina | Ore  | Costo |
| -------- | ---- | ----- |
| 1        | 1.5  | 2.00  |
| 2        | 4.0  | 2.50  |
| 3        | 24.0 | 10.00 |
| TOTAL    | 29.5 | 14.50 |

## Versione un po' più complessa

Al posto di inserire le ore del parcheggio, va inserito l'orario di ingresso e quello di uscita di ogni macchina, per il resto il programma è lo stesso. Utilizzare una funzione di supporto per la trasformazione orario ingresso - orario uscita nel numero di ore parcheggiate, in modo poi da utilizzare la funzione *calcolaCosti* definita in precedenza per il calcolo dei costi. Decidere in maniera autonoma quali saranno i parametri e l'eventuale valore di ritorno della funzione.
