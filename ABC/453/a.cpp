#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int idx = 0;
  while (idx < n && s[idx] == 'o') {
    idx++;
  }

  for (int i = idx; i < n; i++) {
    cout << s[i];
  }
  cout << endl;
}