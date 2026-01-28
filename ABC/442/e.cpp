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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<P> p;
    map<P, vector<int>> mp;
    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y != 0)
        {
            y /= abs(y);
        }
        else if (x != 0 && y == 0)
        {
            x /= abs(x);
        }
        else
        {
            int g = gcd(abs(x), abs(y));
            x /= g;
            y /= g;
        }
        if (mp[{x, y}].size() == 0)
        {
            p.push_back({x, y});
        }
        mp[{x, y}].push_back(i);
    }

    auto getQuadrant = [](int x, int y)
    {
        if (x > 0 && y >= 0)
        {
            return 1;
        }
        if (x <= 0 && y > 0)
        {
            return 2;
        }
        if (x < 0 && y <= 0)
        {
            return 3;
        }
        return 4;
    };

    sort(p.begin(), p.end(), [&](P a, P b)
         {
             int q1 = getQuadrant(a.first, a.second);
             int q2 = getQuadrant(b.first, b.second);
             if (q1 != q2)
             {
                 return q1 > q2;
             }

             ll c = (ll)a.first * b.second - (ll)a.second * b.first;
             if (c != 0)
             {
                 return c < 0;
             }
             
             return false; });

    map<int, int> rev;
    vector<int> a(p.size() + 1);
    rep(i, p.size())
    {
        a[i + 1] = mp[p[i]].size();
        for (auto e : mp[p[i]])
        {
            rev[e] = i;
        }
    }

    for (int i = 0; i < p.size(); i++)
    {
        a.push_back(a[i + 1]);
    }

    rep(i, a.size() - 1) a[i + 1] += a[i];

    rep(qi, q)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int l = rev[x], r = rev[y];
        if (l > r)
        {
            r += p.size();
        }
        int d = a[r + 1] - a[l];
        cout << d << endl;
    }

    return 0;
}
