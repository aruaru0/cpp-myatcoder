#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

using PP = pair<ll, ll>;

int main()
{
    ll L, R;
    cin >> L >> R;

    auto f = [&](auto f, ll l, ll r) -> vector<PP>
    {
        if (L <= l && r <= R)
        {
            return {{l, r}};
        };
        ll m = (l + r) / 2;
        if (R <= m)
        {
            return f(f, l, m);
        }
        if (m <= L)
        {
            return f(f, m, r);
        }

        auto x = f(f, l, m);
        auto y = f(f, m, r);
        copy(y.begin(), y.end(), back_inserter(x));
        return x;
    };

    auto ans = f(f, 0, 1ll << 60);
    cout << ans.size() << endl;
    for (auto p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }
}