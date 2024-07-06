#include <iostream>
#include <vector>

using namespace std;
const int mod = 1e9 + 7;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> g;

    int sz = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            sz++;
        }
        else if (sz != 0)
        {
            g.emplace_back(sz + 1);
            sz = 0;
        }
    }
    if (sz != 0)
    {
        g.emplace_back(sz + 1);
    }
    ll ans = 1;
    for (auto x : g)
    {
        ans *= (x + 1) / 2;
        ans %= mod;
    }
    cout << ans << endl;
}