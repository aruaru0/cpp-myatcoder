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
    int n, q;
    cin >> n >> q;
    map<int, int> mp;

    int cur = 0;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            cur ^= mp[x];
            mp[x]++;
            cur ^= mp[x];
        }
        else
        {
            cur = 0;
            vector<int> zeros;
            for (auto [e, cnt] : mp)
            {
                mp[e]--;
                cur ^= mp[e];
                if (mp[e] == 0)
                {
                    zeros.push_back(e);
                }
            }

            for (auto e : zeros)
            {
                mp.erase(e);
            }
        }
        cout << cur << endl;
    }

    return 0;
}
