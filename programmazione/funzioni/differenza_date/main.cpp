#include <iostream>

/*

 17/10/2000 => 17 + (i giorni di gennaio + i giorni di
                        febbraio + ... + giorni di settembre) +
                        tutti i giorni degli anni compresi tra l'anno
                        0 a il 1999. => 876543
 16/10/2000 => 876542



*/
using namespace std;

//Ritorna 1 se è bisestile, zero altrimenti
int bisestile(int a)
{
    if (a % 400 == 0)
        return 1;
    else if (a % 100 == 0)
        return 0;
    else if (a % 4 == 0)
        return 1;
    else
        return 0;
}

//Ritorna i giorni del mese m
int giorni_del_mese(int m, int a)
{
    if (m == 2)
        return 28 + bisestile(a);
    else if (m == 11 || m == 4 || m == 6 || m == 9)
        return 30;
    else
        return 31;
}

//Ritorna il numero di giorni a partire dal 1 gennaio
//fino ad arrivare al mese m escluso
int giorni_dei_mesi(int m, int a)
{
    int giorni = 0;
    for (int i = 1; i < m; i++)
        giorni += giorni_del_mese(i, a);
    return giorni;
}

int giorni_degli_anni(int a)
{
    int giorni = 0;
    for (int i = 0; i < a; i++)
        giorni += 365 + bisestile(i);
    return giorni;
}

//Trasforma una data in giorni a partire
//dal 1 gennaio dell'anno 0
int trasforma_in_giorni(int g, int m, int a)
{
    int giorni = 0;
    //con data g = 12, m = 2 e a = 2
    //giorni = 12 + 31 + 365*2
    giorni = g + giorni_dei_mesi(m, a) + giorni_degli_anni(a);
    return giorni;
}

//Ritorna la differenza in giorni tra due date
int differenza_date(int g1, int m1, int a1,
                    int g2, int m2, int a2)
{
    int giorniData1 = trasforma_in_giorni(g1, m1, a1);
    int giorniData2 = trasforma_in_giorni(g2, m2, a2);
    return giorniData1 - giorniData2;
}

int main()
{
    cout << differenza_date(2, 12, 2020, 17, 10, 2018) << endl;
    return 0;
}
