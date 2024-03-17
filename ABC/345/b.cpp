#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    ll x, ans;
    cin >> x;
 
    if (x > 0) {
        ans = (x+9)/10;
    } else {
        ans = (-x)/10;
        ans *= -1;
    }
    cout << ans << endl;
}