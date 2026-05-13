#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int lwb(const vector<int> &a, int x) {
  return lower_bound(a.begin(), a.end(), x) - a.begin();
}

int main() {
  int n, m;
  cin >> n >> m;
  n += 2;
  vector<vector<int>> rs(n), ls(n);
  const int INF = 1001001001;
  vector<int> minR(n, INF);
  rep(i, m) {
    int l, r;
    cin >> l >> r;
    rs[l].push_back(r);
    ls[r].push_back(l);
    minR[l] = min(minR[l], r);
  }
  rep(i, n) sort(rs[i].begin(), rs[i].end());
  rep(i, n) sort(ls[i].begin(), ls[i].end());
  for (int i = n - 2; i >= 0; i--)
    minR[i] = min(minR[i], minR[i + 1]);

  int q;
  cin >> q;
  rep(qi, q) {
    int l, r;
    cin >> l >> r;
    auto solve = [&]() {
      int cnt = lwb(rs[l], r + 1) - lwb(rs[l], r);
      if (cnt) {
        if (minR[l] < r || minR[l + 1] <= r)
          return true;
        return cnt >= 2;
      } else {
        int ri = lwb(rs[l], r) - 1;
        int li = lwb(ls[r], l);
        if (ri < 0 || li >= ls[r].size())
          return false;
        return rs[l][ri] + 1 >= ls[r][li];
      }
    };
    if (solve())
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}