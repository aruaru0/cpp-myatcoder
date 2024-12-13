#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

void chmax(ll& x, ll y) { x = max(x,y);}

int main() {
  int n, x, K;
  cin >> n >> x >> K;
  vector<tuple<int,int,int>> items;
  rep(i,n) {
    int p, u, c;
    cin >> p >> u >> c;
    items.emplace_back(c,p,u);
  }
  sort(items.begin(), items.end());

  vector<vector<ll>> dp(x+1, vector<ll>(2));

  int pre_c = -1;
  for (auto [c,p,u] : items) {
    if (pre_c != c) {
      rep(i,x+1) chmax(dp[i][0], dp[i][1]);
      pre_c = c;
    }
    vector<vector<ll>> old(x+1, vector<ll>(2));
    swap(dp,old);
    rep(i,x+1) {
      rep(j,2) chmax(dp[i][j], old[i][j]);
      int ni = i+p;
      if (ni <= x) {
        chmax(dp[ni][1], old[i][1]+u);
        chmax(dp[ni][1], old[i][0]+u+K);
      }
    }
  }

  ll ans = dp[x][1];
  cout << ans << endl;
  return 0;
}