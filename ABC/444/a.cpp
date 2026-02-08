#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    bool ok = true;
    int x = n % 10;
    while (n > 0)
    {
        if (x != n % 10)
        {
            ok = false;
            break;
        }
        n /= 10;
    }
    if (ok)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}