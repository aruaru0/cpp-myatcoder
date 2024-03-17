#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    bool ok = true;

    if (s[0] != '<') {
        ok = false;
    }
    if (s[n-1] != '>') {
        ok = false;
    }
    for(int i = 1; i < n-1; i++) {
        if (s[i]!='=') {
            ok = false;
        }
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}