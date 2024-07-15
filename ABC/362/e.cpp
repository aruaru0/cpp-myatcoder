#include <iostream>
#include <vector>
#include <map>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

using mint = modint998244353;

class key
{
public:
    int a, b, c;

    // コンストラクタ
    key(int a, int b, int c) : a(a), b(b), c(c) {}

    // 比較演算子をオーバーロード
    bool operator<(const key &other) const
    {
        if (a != other.a)
            return a < other.a;
        if (b != other.b)
            return b < other.b;
        return c < other.c;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    map<key, mint> mp;

    auto f = [&](auto f, int i, int j, int cnt) -> mint
    {
        if (cnt == 2)
        {
            return 1;
        }
        if (mp.find(key(i, j, cnt)) != mp.end())
        {
            return mp[key(i, j, cnt)];
        }

        mint ret = 0;
        int diff = a[j] - a[i];
        for (int k = j + 1; k < n; k++)
        {
            if (a[k] - a[j] == diff)
            {
                ret += f(f, j, k, cnt - 1);
            }
        }

        mp[key(i, j, cnt)] = ret;
        return ret;
    };

    vector<mint> ans(n + 1, 0);
    ans[1] = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = 2; k < n + 1; k++)
            {
                ans[k] += f(f, i, j, k);
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        cout << ans[i].val() << " ";
    }
    cout << endl;
}