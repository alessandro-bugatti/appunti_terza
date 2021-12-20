# Esempio di utilizzo di colori

Nella grafica i colori sono rappresentati attraverso
dei tipi di dato che vengono "creati" per contenere
le informazioni necessarie a definire un colore e che
sono specifici per ogni libreria, seppure equivalenti 
tra di loro.

La libreria RayLib utilizza il tipo di dato *Color* 
che è pensato per contenere i tre canali di colore
rosso, verde e blu (RGB in inglese), i cui valori 
devono essere compresi tra 0 e 255, e il canale *alpha* 
che indica il grado di trasparenza, anche questo da 0 a 255 (0 - completamente
trasparente e 255 - completamente opaco).

Per rappresentare un colore quindi bisogna valorizzare
tutti e quattro i campi in base a quello che si vuole
ottenere. Ad esempio il rosso puro completamente opaco 
sarebbe:

    Color rosso = {255, 0, 0, 255};

Mentre ad esempio il verde chiaro potrebbe essere:

    Color verde_chiaro = {0, 200, 0, 255};

Altri due esempi in cui potrebbe non essere così ovvio
quale sia il colore risultante dalla combinazione dei 
tre canali sono i seguenti:

    Color giallo_acido = {221, 234, 6, 255};
    Color azzurro_trasparente = {12, 231, 190, 128};

Nel caso dell'ultimo colore si ha anche una trasparenza,
poichè il valore del canale *alpha* è una via di mezzo tra
completamenete opaco e completamente trasparente.

Il bianco e il nero sono invece fatti così:

    Color bianco = {255, 255, 255, 255};
    Color nero = {0, 0, 0, 255};


Una volta definita una variabile di tipo <code>Color</code> 
è possibile poi utilizzarla, ad esempio per disegnare un
rettangolo rosso, in questo modo:

    DrawRectangle(0, 0, screenWidth/2, screenHeight/2, rosso);