#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;

  cout << s.substr(n, s.size() - 2 * n) << endl;
}