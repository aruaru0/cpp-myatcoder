#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    for (auto e : s)
    {
        if ('0' <= e && e <= '9')
        {
            cout << e;
        }
    }
    cout << endl;
}