#include <iostream>
#include <map>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int N, M;
  cin >> N >> M;

  map<int, int> m;
  rep(i, N) {
    int f;
    cin >> f;
    m[f]++;
  }

  if (N == m.size()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  if (M == m.size()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}