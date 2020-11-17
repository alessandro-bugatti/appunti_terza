//Disegno di rombi

#include <iostream>

using namespace std;

/**

  *
 ***
*****

*
***
*****
*/

int main()
{
    int N;
    cout << "Inserisci il lato: ";
    cin >> N;
    int asterischi = 1;
    int spazi = N - 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < spazi; j++)
            cout << " ";
        for (int j = 0; j < asterischi; j++)
            cout << "*";
        cout << endl;
        asterischi += 2;
        spazi--;
    }
    spazi = 1;
    asterischi -= 4;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < spazi; j++)
            cout << " ";
        for (int j = 0; j < asterischi; j++)
            cout << "*";
        cout << endl;
        asterischi -= 2;
        spazi++;
    }
    return 0;
}
