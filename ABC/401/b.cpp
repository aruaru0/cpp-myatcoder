#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    bool login = false;
    int cnt = 0;
    rep(i, n)
    {
        string s;
        cin >> s;
        if (s == "login")
            login = true;
        else if (s == "logout")
            login = false;
        else if (s == "private" && login == false)
            cnt++;
    }

    cout << cnt << endl;
    return 0;
}
