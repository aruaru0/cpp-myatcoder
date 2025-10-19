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

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    map<string, int> mp;
    int max_cnt = 0;

    rep(i, n-k+1)
    {
        mp[s.substr(i, k)]++;
        max_cnt = max(max_cnt, mp[s.substr(i, k)]);
    }

    cout << max_cnt << endl;
    for(auto [e, cnt] : mp) {
        if (cnt == max_cnt) {
            cout << e << " ";
        }
    }
    cout << endl;


     return 0;
}
