#include <iostream>

using namespace std;

float distanza(float x1, float y1, float x2, float y2)
{
    float cateto1 = x1 - x2;
    float cateto2 = y1 - y2;
    float ipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2);
    return ipotenusa;
}

int main()
{
    cout << distanza(-3, 12, 17, -31) << endl;
    return 0;
}
