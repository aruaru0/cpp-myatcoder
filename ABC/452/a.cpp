#include <iostream>

using namespace std;

int main() {
  int M, D;
  cin >> M >> D;

  int m[] = {1, 3, 5, 7, 9};
  int d[] = {7, 3, 5, 7, 9};

  bool ok = false;
  for (int i = 0; i < 5; i++) {
    if (M == m[i] && D == d[i]) {
      ok = true;
    }
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}