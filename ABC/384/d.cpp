#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll N, S;
    cin >> N >> S;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    ll total = 0;
    rep(i, N) total += A[i];

    ll n = S - (S / total) * total;

    int r = 0;
    ll sum = 0;
    rep(l, 2 * N)
    {
        while (r < 2 * N && sum < n)
        {
            sum += A[r % N];
            r++;
        }
        if (sum == n)
        {
            cout << "Yes" << endl;
            return 0;
        }
        sum -= A[l % N];
    }
    cout << "No" << endl;
    return 0;
}
