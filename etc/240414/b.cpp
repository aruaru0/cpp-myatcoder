#include <iostream>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    if (s == t)
    {
        cout << 0 << endl;
        return 0;
    }

    if (s.size() != t.size())
    {
        cout << -1 << endl;
        return 0;
    }

    int ans = -1;
    for (int i = 0; i < s.size(); i++)
    {
        bool ok = true;
        for (int j = 0; j < s.size(); j++)
        {
            // cout << s[(i + j) % s.size()] << " " << t[j] << endl;
            if (s[(i + j) % s.size()] != t[j])
            {
                ok = false;
            }
        }
        // cout << "-----" << ok << endl;
        if (ok)
        {
            ans = s.size() - i;
        }
    }

    cout << ans << endl;
}