#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s, t;
    cin >> s >> t;

    transform(s.begin(), s.end(), s.begin(), ::toupper);

    int idx = 0;
    for (char c : s)
    {
        if (c == t[idx])
        {
            idx++;
        }
        if (idx == 3)
        {
            break;
        }
    }

    if (idx == 3)
    {
        cout << "Yes" << endl;
        return 0;
    }
    if (idx == 2 && t[2] == 'X')
    {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}
