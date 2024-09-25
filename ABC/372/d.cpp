#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    deque<int> q;

    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        ans.push_back(q.size());
        while (!q.empty() && q.back() < h[i])
            q.pop_back();
        q.push_back(h[i]);
    }

    reverse(ans.begin(), ans.end());
    for (auto e : ans)
        cout << e << " ";
    cout << endl;

    return 0;
}
