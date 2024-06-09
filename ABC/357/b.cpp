#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;

    int low = 0, high = 0;
    rep(i, s.size())
    {
        if (islower(s[i]))
        {
            low++;
        }
        else
        {
            high++;
        }
    }

    // cout << low << ' ' << high << endl;
    if (low > high)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }
    else
    {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    }

    cout << s << endl;

    return 0;
}