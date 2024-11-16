#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string n;
    cin >> n;

    vector<int> a = {1, 2, 2, 3, 3, 3};

    while (true)
    {
        string t;
        for (auto e : a)
        {
            t += to_string(e);
        }

        if (n == t)
        {
            cout << "Yes" << endl;
            return 0;
        }

        if (!next_permutation(a.begin(), a.end()))
        {
            break;
        }
    }

    cout << "No" << endl;

    return 0;
}
