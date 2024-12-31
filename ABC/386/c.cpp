#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool f(string s, string t)
{
    int ns = s.size();
    int nt = t.size();

    if (abs(ns - nt) > 1)
    {
        return false;
    }

    if (ns > nt)
    {
        swap(ns, nt);
        swap(s, t);
    }

    int diff = 0;
    int i = 0, j = 0;
    while (i < ns && j < nt)
    {
        if (s[i] != t[j])
        {
            diff++;
            if (diff > 1)
            {
                return false;
            }
            if (ns != nt)
            {
                j++;
                continue;
            }
        }
        j++;
        i++;
    }
    if (j < nt)
    {
        diff++;
    }

    if (diff > 1)
    {
        return false;
    }
    return true;
}

int main()
{
    int k;
    cin >> k;
    string s, t;

    cin >> s >> t;

    if (f(s, t))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
