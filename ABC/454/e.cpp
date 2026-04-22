#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  a--;
  b--;
  if (n % 2 || (a + b) % 2 == 0) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";

  int h = n, w = n;
  string s, t;
  while (1) {
    if (a >= 2) {
      s += string(w - 1, 'R');
      s += 'D';
      s += string(w - 1, 'L');
      s += 'D';
      h -= 2;
      a -= 2;
    } else if (a < h - 2) {
      t += string(w - 1, 'R');
      t += 'D';
      t += string(w - 1, 'L');
      t += 'D';
      h -= 2;
    } else if (b >= 2) {
      s += string(h - 1, 'D');
      s += 'R';
      s += string(h - 1, 'U');
      s += 'R';
      w -= 2;
      b -= 2;
    } else if (b < w - 2) {
      t += string(h - 1, 'D');
      t += 'R';
      t += string(h - 1, 'U');
      t += 'R';
      w -= 2;
    } else {
      if (a == 0)
        s += "DR";
      else
        s += "RD";
      break;
    }
  }

  reverse(t.begin(), t.end());
  s += t;
  cout << s << endl;
}

int main() {
  int T;
  cin >> T;
  rep(ti, T) solve();
  return 0;
}