# Il Gioco della Vita di Conway

Il **Gioco della Vita** è un automa cellulare ideato dal matematico britannico **John Horton Conway** nel 1970. Nonostante il nome, non è un vero e proprio gioco nel senso tradizionale, ma piuttosto una simulazione matematica che segue semplici regole per determinare l'evoluzione di una popolazione di celle su una griglia.

## Regole del Gioco

Il gioco si svolge su una griglia bidimensionale di celle, dove ogni cella può trovarsi in uno di due stati:
- **Viva** (attiva, rappresentata solitamente da un quadrato o un punto colorato)
- **Morta** (inattiva, rappresentata da uno spazio vuoto)

Ogni cella interagisce con le **otto celle adiacenti** e, ad ogni iterazione, evolve seguendo queste semplici regole:

1. **Sopravvivenza**: Una cella viva con **2 o 3** celle vive vicine **rimane viva**.
2. **Morte per isolamento**: Una cella viva con **meno di 2** celle vive vicine **muore** (solitudine).
3. **Morte per sovraffollamento**: Una cella viva con **più di 3** celle vive vicine **muore** (sovrappopolazione).
4. **Nascita**: Una cella morta con **esattamente 3** celle vive vicine **diventa viva** (riproduzione).

## Comportamenti ed Evoluzione

Grazie a queste semplici regole emergono comportamenti complessi e interessanti, tra cui:
- **Oscillatori**: Strutture che cambiano stato periodicamente (es. il "Blinker").
- **Navicelle**: Configurazioni che si spostano sulla griglia (es. il "Glider").
- **Strutture stabili**: Configurazioni che non cambiano nel tempo (es. il "Blocchetto").

### Esempi di Strutture Comuni

#### Blinker (Oscillatore)
Un Blinker oscilla tra due stati:
```
O O O
```
e dopo un'iterazione:
```
O
O
O
```

#### Glider (Navicella)
Il Glider si sposta diagonalmente sulla griglia:
```
. O .
. . O
O O O
```

#### Blocchetto (Struttura Stabile)
Il Blocchetto rimane invariato nel tempo:
```
O O
O O
```

![Esempio](life.gif "Esempio di Life")

---
**Curiosità**: Sebbene sia deterministico, il Gioco della Vita può produrre comportamenti imprevedibili.

