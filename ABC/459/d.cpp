#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// coutにvector<int>を表示させる
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
    }
    os << "]";
    return os;
}

void solve()
{
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (auto c : s)
        cnt[c - 'a']++;
    vector<pair<int, char>> cs;
    rep(i, 26) cs.emplace_back(cnt[i], 'a' + i);
    sort(cs.begin(), cs.end());

    int mx = cs[cs.size() - 1].first;

    if (mx > (s.size() + 1) / 2)
    {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;

    vector<char> ans(s.size());

    int pos = 0;
    for (int i = 25; i >= 0; i--)
    {
        auto [cnt, c] = cs[i];
        rep(j, cnt)
        {
            ans[pos] = c;
            pos += 2;
            if (pos >= s.size())
                pos = 1;
        }
    }

    // ansをstringとして表示
    string ans_str(ans.begin(), ans.end());
    cout << ans_str << endl;
}

int main()
{
    int t;
    cin >> t;

    rep(i, t) solve();

    return 0;
}
