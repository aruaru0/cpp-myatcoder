#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int q;
    cin >> q;
    vector<int> x(q), y(q);
    rep(i, q)
    {
        cin >> x[i] >> y[i];
    }

    const int n = 2e7;
    int D = max<int>(1, n / sqrt(q));

    vector<int> blockId(q);
    rep(i, q) blockId[i] = x[i] / D;

    vector<int> is(q);
    rep(i, q) is[i] = i;
    sort(is.begin(), is.end(), [&](int i, int j) -> bool
         {
    if (blockId[i] != blockId[j]) return blockId[i] < blockId[j];
    return (y[i] < y[j]) ^ (blockId[i]%2); });

    rep(i, q)
    {
        if (is[i] == 0)
        {
            rotate(is.begin(), is.begin() + i, is.end());
        }
    }

    rep(i, q) cout << is[i] + 1 << ' ';
    cout << endl;
    return 0;
}