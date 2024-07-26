#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll, ll>;

bool isPalindrome(const string &s)
{
    if (s.find("0") != string::npos)
        return false;
    string rs = s;
    reverse(rs.begin(), rs.end());
    return s == rs;
}

int main()
{
    ll n;
    cin >> n;

    // ペアを見つける
    vector<P> ps;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i)
            continue;
        string s = to_string(i);
        reverse(s.begin(), s.end());
        ll j = stoll(s);
        if (n % j)
            continue;
        if (s.find("0") != string::npos)
            continue;
        if (i <= j)
        {
            ps.emplace_back(i, j);
        }
    }

    auto f = [&](auto f, ll n) -> string
    {
        // n が回文になっていたら返す
        if (isPalindrome(to_string(n)))
        {
            return to_string(n);
        }

        // ペアの分繰り返す
        for (auto [x, y] : ps)
        {
            ll xy = x * y;
            // ペアで割れない場合はスキップ
            if (n % xy)
                continue;

            // ペアで割れる場合は、繰り返し
            string s = f(f, n / xy);
            if (s == "-1")
                continue;
            return to_string(x) + "*" + s + "*" + to_string(y);
        }

        return "-1";
    };

    cout << f(f, n) << endl;
    return 0;
}