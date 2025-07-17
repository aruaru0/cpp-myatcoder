#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using mint = modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll N;
    cin >> N;

    mint sum = 0;
    ll cnt = 0;
    for (ll i = 1; i * i <= N; i++)
    {
        cnt++;
        sum += N / i;
    }

    sum = 2 * sum - cnt * cnt;
    mint ans;

    ans = ((mint)N * (N + 1) / 2 - sum);

    cout << ans.val() << endl;

    return 0;
}
