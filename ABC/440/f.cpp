#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

using S = multiset<int>;

struct Divset
{
    S ls, rs;
    int k;
    ll rsum;
    Divset() : k(0), rsum(0) {}
    void fix()
    {
        while (rs.size() < k)
        {
            int x = *ls.rbegin();
            rs.insert(x);
            rsum += x;
            ls.erase(ls.find(x));
        }
        while (rs.size() > k)
        {
            int x = *rs.begin();
            ls.insert(x);
            rs.erase(rs.find(x));
            rsum -= x;
        }
    }

    void add(int x)
    {
        rs.insert(x);
        rsum += x;
        fix();
    }
    void del(int x)
    {
        if (ls.find(x) != ls.end())
            ls.erase(ls.find(x));
        else
            rs.erase(rs.find(x)), rsum -= x;
        fix();
    }
    void inc()
    {
        k++;
        fix();
    }
    void dec()
    {
        k--;
        fix();
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    ll sum = 0, sum2 = 0;
    S s1, s2;
    Divset ds;
    auto add = [&](int a, int b)
    {
        ds.add(a);
        sum += a;
        if (b == 2)
            ds.inc(), sum2 += a;
        if (b == 1)
            s1.insert(a);
        else
            s2.insert(a);
    };
    auto del = [&](int a, int b)
    {
        if (b == 1)
            s1.erase(s1.find(a));
        else
            s2.erase(s2.find(a));
        if (b == 2)
            ds.dec(), sum2 -= a;
        ds.del(a);
        sum -= a;
    };

    vector<int> a(n), b(n);
    rep(i, n)
    {
        cin >> a[i] >> b[i];
        add(a[i], b[i]);
    }

    rep(qi, q)
    {
        int i, x, y;
        cin >> i >> x >> y;
        --i;
        del(a[i], b[i]);
        a[i] = x;
        b[i] = y;
        add(a[i], b[i]);

        ll ans = sum + ds.rsum;
        if (sum2 != 0 && ds.rsum == sum2)
        {
            ans -= *s2.begin();
            if (sum2 < sum)
                ans += *s1.rbegin();
        }
        cout << ans << '\n';
    }
    return 0;
}