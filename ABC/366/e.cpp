#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int M = 1e6;

vector<ll> f(vector<int> x)
{
    int n = x.size();
    // x[i]を＋方向にずらす（max(D)+max(x)分）
    rep(i, n)
    {
        x[i] += M * 2;
    }
    // 原点からの距離を求める
    ll s = 0;
    rep(i, n)
    {
        s += x[i];
    }
    // 各座標からの距離を求める
    vector<ll> res(M * 4 + 1);
    res[0] = s;
    int k = 0;
    sort(x.begin(), x.end());
    // 原点から＋方向にずらしながら、距離を補正
    for (int i = 1; i <= M * 4; i++)
    {
        while (k < n && x[k] < i)
        {
            k++;
        }
        // １つずれるのでn減る。ただし、iがx[]を超えた点は引いて足す。nからｋ個は除外して、左側に遠ざかるkを足す
        s -= n - k * 2;
        res[i] = s;
    }
    return res;
}

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    vector<ll> a = f(x);
    vector<ll> b = f(y);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;
    int j = b.size() - 1;
    rep(i, a.size())
    {
        while (j >= 0 && a[i] + b[j] > d)
            j--;

        ans += j + 1;
    }
    cout << ans << endl;
    return 0;
}
