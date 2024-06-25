#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

// sが回文かどうか調べる
bool is_palindrome(string s)
{
    int n = s.size();
    rep(i, n)
    {
        if (s[i] != s[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    map<string, ll> dp;
    dp[string("............").substr(0, k - 1)] = 1;

    const int mod = 998244353;

    rep(i, n)
    {
        map<string, ll> tmp;
        if (s[i] != 'A')
        {
            for (auto p : dp)
            {
                tmp[p.first + "B"] = p.second;
            }
        }
        if (s[i] != 'B')
        {
            for (auto p : dp)
            {
                tmp[p.first + "A"] = p.second;
            }
        }

        // cout << "---" << endl;
        // for (auto p : tmp)
        // {
        //     cout << p.first << " : " << p.second << endl;
        // }
        dp.clear();
        for (auto p : tmp)
        {
            if (is_palindrome(p.first))
                continue;
            dp[p.first.substr(1, k)] += p.second;
            dp[p.first.substr(1, k)] %= mod;
        }
    }
    ll ans = 0;
    for (auto p : dp)
    {
        ans += p.second;
        ans %= mod;
    }

    cout << ans << endl;
}