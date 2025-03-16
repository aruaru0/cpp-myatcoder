#include <iostream>
using namespace std;
int main()
{
    double t;
    cin >> t;
    if (38.0 <= t)
    {
        cout << 1 << endl;
    }
    else if (37.5 <= t && t < 38.0)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << 3 << endl;
    }
}
