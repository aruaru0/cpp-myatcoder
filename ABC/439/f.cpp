#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
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

using mint = modint998244353;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    vector<ll> L(n);
    fenwick_tree<ll> bitL(n + 2);
    rep(i, n)
    {
        L[i] = bitL.sum(0, p[i]);
        bitL.add(p[i], 1);
    }
    vector<ll> R(n);
    fenwick_tree<ll> bitR(n + 2);
    for (int i = n - 1; i >= 0; i--)
    {
        R[i] = bitR.sum(0, p[i]);
        bitR.add(p[i], 1);
    }

    vector<mint> pow2(n + 1);
    vector<mint> inv_pow2(n + 1);
    pow2[0] = 1;
    inv_pow2[0] = 1;
    mint inv2 = mint(1) / 2;

    rep(i, n)
    {
        pow2[i + 1] = pow2[i] * 2;
        inv_pow2[i + 1] = inv_pow2[i] * inv2;
    }

    mint ans = 0;
    mint currentSumL = 0;

    rep(i, n)
    {
        mint term1 = L[i] * R[i];
        ans += term1;
        if (i > 0)
        {
            mint trem2 = R[i] * pow2[i - 1];
            trem2 *= currentSumL;
            ans += trem2;
        }
        mint addVal = L[i] * inv_pow2[i];
        currentSumL += addVal;
    }

    cout << ans.val() << endl;
    return 0;
}
