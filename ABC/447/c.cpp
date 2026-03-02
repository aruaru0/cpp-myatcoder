#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// coutにvector<int>を表示させる
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
    }
    os << "]";
    return os;
}

int main()
{
    string s, t;
    cin >> s >> t;

    string st, tt;
    rep(i, s.size())
    {
        if (s[i] != 'A')
            st += s[i];
    }
    rep(i, t.size())
    {
        if (t[i] != 'A')
            tt += t[i];
    }
    if (st != tt)
    {
        cout << -1 << endl;
        return 0;
    }

    int cnt = 0, i = 0, j = 0;
    while (i < s.size() || j < t.size())
    {
        // skip A
        int cs = 0, ct = 0;
        while (i < s.size() && s[i] == 'A')
            cs++, i++;
        while (j < t.size() && t[j] == 'A')
            ct++, j++;
        cnt += abs(cs - ct);
        i++;
        j++;
    }

    cout << cnt << endl;

    return 0;
}
