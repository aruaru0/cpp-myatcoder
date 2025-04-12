#include <iostream>

using namespace std;

int main()
{
    int x, y, z, s;
    cin >> x >> y >> z >> s;

    x = max(x, max(y, z));
    if (x >= s)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}