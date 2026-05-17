#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// coutにvector<int>を表示させる
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  os << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
  }
  os << "]";
  return os;
}

int main() {
  int h, w;
  cin >> h >> w;

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
          cnt++;
        }
      }
      cout << cnt << " ";
    }
    cout << endl;
  }

  return 0;
}
