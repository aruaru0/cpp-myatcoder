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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    auto f = [](string x, string y)
    {
        int cnt = 0;
        rep(i, x.size())
        {
            if (x[i] != y[i])
                cnt++;
        }
        return cnt <= 1;
    };

    vector<int> cnt(n, 0);
    rep(i, m)
    {
        string t;
        cin >> t;
        vector<int> same, near;
        rep(j, n)
        {
            if (s[j].size() != t.size())
                continue;
            if (s[j] == t)
            {
                same.push_back(j);
                break;
            }
            if (f(s[j], t))
            {
                near.push_back(j);
            }
        }
        if (same.size() == 1)
        {
            cnt[same[0]]++;
        }
        else if (near.size() == 1)
        {
            cnt[near[0]]++;
        }
    }

    rep(i, n) cout << cnt[i] << endl;

    return 0;
}
