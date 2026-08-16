#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if ((a + b == 9) || (a - b == 9) || (a * b == 9) || (a == b * 9))
    {
        cout << "Nine" << endl;
    }
    else
    {
        cout << "Nein" << endl;
    }
}