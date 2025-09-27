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
    int n;
    cin >> n;
    vector<int> a(n);

    rep(i, n) cin >> a[i];

    set<int> s;
    rep(i, n)
    {
        if (a[i] != -1)
        {
            if (s.find(a[i]) != s.end())
            {
                cout << "No" << endl;
                return 0;
            }
            s.insert(a[i]);
        }
    }

    vector<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (s.find(i) == s.end())
        {
            q.push_back(i);
        }
    }

    int idx = 0;
    cout << "Yes" << endl;
    rep(i, n)
    {
        if (a[i] == -1)
        {
            cout << q[idx] << " ";
            idx++;
        }
        else
        {
            cout << a[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
