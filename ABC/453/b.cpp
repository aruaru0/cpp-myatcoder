#include <iostream>

using namespace std;

int main() {
  int T, X;
  cin >> T >> X;

  const int inf = 10000;
  int x = -inf;
  for (int i = 0; i <= T; i++) {
    int a;
    cin >> a;
    if (abs(a - x) >= X) {
      x = a;
      cout << i << " " << x << endl;
    }
  }
}