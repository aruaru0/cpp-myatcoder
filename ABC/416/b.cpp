#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    bool flg = true;
    for (auto c : s)
    {
        if (c == '#')
        {
            cout << '#';
            flg = true;
        }
        else if (flg)
        {
            cout << 'o';
            flg = false;
        }
        else
        {
            cout << '.';
        }
    }
    cout << endl;
}