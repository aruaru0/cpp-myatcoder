#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int x = s[0] - '0';
    int y = s[2] - '0';

    if (y == 8)
    {
        x++;
        y = 1;
    }
    else
    {
        y++;
    }
    cout << x << "-" << y << endl;

    return 0;
}