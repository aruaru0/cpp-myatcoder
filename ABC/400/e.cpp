#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll mmax = 1e6 + 10;
    vector<int> m(mmax, 0);

    for (int i = 2; i < mmax; i++)
    {
        if (m[i] == 0)
            for (int j = i; j < mmax; j += i)
            {
                m[j]++;
            }
    }

    vector<ll> sq;
    rep(i, mmax)
    {
        if (m[i] == 2)
        {
            sq.push_back((ll)i * i);
        }
    }

    int q;
    cin >> q;
    rep(qi, q)
    {
        ll a;
        cin >> a;

        int l = 0, r = sq.size();
        while (l + 1 != r)
        {
            int mid = (l + r) / 2;
            if (sq[mid] > a)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        cout << sq[l] << endl;
    }

    return 0;
}
