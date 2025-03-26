#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, r, c;
    cin >> n >> r >> c;
    string s;
    cin >> s;

    set<P> st;
    int r0 = 0, c0 = 0;
    st.insert({r0, c0});
    rep(i, n)
    {
        switch (s[i])
        {
        case 'N':
            r++;
            r0++;
            break;
        case 'S':
            r--;
            r0--;
            break;
        case 'E':
            c--;
            c0--;
            break;
        case 'W':
            c++;
            c0++;
            break;
        }
        st.insert({r0, c0});
        if (st.find({r, c}) != st.end())
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }

    cout << endl;

    return 0;
}
