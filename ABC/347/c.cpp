#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    int ab = a + b;
    set<ll> st;
    rep(i, n)
    {
        int d;
        cin >> d;
        st.insert(d % ab);
    }

    vector<ll> p;

    for (auto e : st)
    {
        p.emplace_back(e);
    }
    // pをソートする
    sort(p.begin(), p.end());

    if (p.size() == 1)
    {
        cout << "Yes" << endl;
        return 0;
    }

    p.emplace_back(p[0]);

    for (int i = 0; i < p.size() - 1; i++)
    {
        ll d = p[i + 1] - p[i];
        if (d < 0)
        {
            d += ab;
        }
        if (d > b)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}