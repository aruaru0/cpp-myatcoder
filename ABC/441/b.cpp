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
    string s, t;
    cin >> s >> t;

    int q;
    cin >> q;

    rep(qi, q)
    {
        string w;
        cin >> w;

        bool taka = true, aoki = true;
        for (int i = 0; i < w.size(); i++)
        {
            {
                bool ok = false;
                for (int j = 0; j < n; j++)
                {
                    if (w[i] == s[j])
                    {
                        ok = true;
                        break;
                    }
                }
                if (ok == false)
                {
                    taka = false;
                }
            }
            {
                bool ok = false;

                for (int j = 0; j < m; j++)
                {
                    if (w[i] == t[j])
                    {
                        ok = true;
                        break;
                    }
                }
                if (ok == false)
                {
                    aoki = false;
                }
            }
        }
        if (taka == true && aoki == false)
        {
            cout << "Takahashi" << endl;
        }
        else if (taka == false && aoki == true)
        {
            cout << "Aoki" << endl;
        }
        else
        {
            cout << "Unknown" << endl;
        }
    }

    return 0;
}
