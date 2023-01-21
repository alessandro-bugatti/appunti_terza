# Conversioni tra basi diverse

Scrivere delle funzioni per convertire:
- un numero decimale in un numero binario
- un numero binario in un numero decimale
- un numero decimale in un numero ottale
- un numero ottale in un numero binario

Viene richiesto di usare delle variabili di tipo `long long` per rappresentare ogni tipo
di numero, sia decimale, che ottale, che binario, sarà l'insieme di cifre e l'utilizzo che 
se ne fa a stabilire che base ha. Se ad esempio l'utente deve inserire il numero binario 
`1011010`, dal punto di vista della variabile che lo contiene sarà comunque un numero in
base dieci, sarà la funzione che ad esempio lo deve convertire in decimale a leggere ogni
cifra come un bit in una certa posizione e a trasformarlo nel numero `80`.

Scrivere poi un programma che, utilizzando le funzioni scritte in precedenza e attraverso
un menù, permetta all'utente di scegliere una conversione, gli faccia inserire un numero e 
lo mostri seguendo la conversione scelta.