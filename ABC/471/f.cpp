#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    auto cmp = [&](const string &a, const string &b)
    {
        if (a.size() == b.size())
            return a > b;
        return a.size() > b.size();
    };
    sort(s.begin(), s.end(), cmp);

    string ans = "0";
    auto upd = [&](vector<string> s)
    {
        sort(s.begin(), s.end(), [&](const string &a, const string &b)
             { return a + b > b + a; });
        string now;
        for (string a : s)
            now += a;
        reverse(now.begin(), now.end());
        while (now.size() > 1 && now.back() == '0')
            now.pop_back();
        reverse(now.begin(), now.end());
        if (cmp(now, ans))
            ans = now;
    };
    upd(vector<string>(s.begin(), s.begin() + k));
    {
        string best = "0";
        for (int i = k; i < n; i++)
        {
            if (stoll(best) < stoll(s[i]))
                best = s[i];
        }
        vector<string> t(s.begin(), s.begin() + (k - 1));
        t.push_back(best);
        upd(t);
    }

    cout << ans << endl;
    return 0;
}