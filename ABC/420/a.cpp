#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    int diff = (x + y) % 12;

    if (diff == 0)
    {
        cout << diff + 12 << endl;
    }
    else
    {
        cout << diff << endl;
    }
}