#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  // (r,c)に方向dから突入したときの最小コスト
  vector pre(h, vector(w, vector<int>(4, -1)));

  queue<tuple<int, int, int>> q;
  auto push = [&](int i, int j, int v, int pv) {
    if (pre[i][j][v] != -1)
      return;
    pre[i][j][v] = pv;
    q.emplace(i, j, v);
  };

  rep(i, h) rep(j, w) {
    if (s[i][j] == 'S') {
      rep(v, 4) push(i, j, v, 9);
    }
  }

  while (q.size()) {
    auto [i, j, v] = q.front();
    q.pop();
    if (s[i][j] == 'G') {
      cout << "Yes\n";
      string ans;
      while (pre[i][j][v] != 9) {
        ans += "ULDR"[v];
        int pv = pre[i][j][v];
        i -= di[v];
        j -= dj[v];
        v = pv;
      }
      reverse(ans.begin(), ans.end());
      cout << ans << endl;
      return 0;
    }
    rep(nv, 4) {
      if (s[i][j] == 'o' && nv != v)
        continue;
      if (s[i][j] == 'x' && nv == v)
        continue;
      int ni = i + di[nv], nj = j + dj[nv];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w)
        continue;
      if (s[ni][nj] == '#')
        continue;
      push(ni, nj, nv, v);
    }
  }

  cout << "No\n";
  return 0;
}