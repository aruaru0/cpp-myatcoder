#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    string t;
    for (auto e : s)
    {
        if (e == '.')
        {
            continue;
        }
        t += e;
    }
    cout << t << endl;
}