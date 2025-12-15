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

    set<P> s;
    int cnt = 0;
    rep(i, m)
    {
        int r, c;
        cin >> r >> c;
        if (s.find(P(r, c)) == s.end() && s.find(P(r, c + 1)) == s.end() && s.find(P(r + 1, c)) == s.end() && s.find(P(r + 1, c + 1)) == s.end())
        {
            s.insert(P(r, c));
            s.insert(P(r, c + 1));
            s.insert(P(r + 1, c));
            s.insert(P(r + 1, c + 1));
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
