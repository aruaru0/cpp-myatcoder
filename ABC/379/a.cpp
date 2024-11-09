#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;

    string t = {s[1], s[2], s[0]};
    string u = {s[2], s[0], s[1]};

    cout << t << " " << u << endl;

    return 0;
}
