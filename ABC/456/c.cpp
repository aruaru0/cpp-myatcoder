#include <iostream>

using namespace std;

using ll = long long;

int main() {
  string s;
  cin >> s;
  int n = s.length();

  ll mod = 998244353;

  ll ans = 1;
  ll cur = 1;
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == s[i]) {
      cur = 1;
    } else {
      cur++;
    }
    ans += cur;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}