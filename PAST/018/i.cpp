#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int Q;
    cin >> Q;

    vector<list<char>> rows(Q + 1);

    int r = 0, w = 0;
    auto it = rows[r].begin();
    for (int i = 0; i < Q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            char c;
            cin >> c;
            it = rows[r].insert(it, c);
            ++it;
            w++;
        }
        else if (t == 2)
        {
            it = rows[r].begin();
            w = 0;
        }
        else if (t == 3)
        {
            r++;
            it = rows[r].begin();
            w = 0;
        }
    }

    cout << r + 1 << " " << w + 1 << endl;

    for (int i = 0; i <= r; i++)
    {
        cout << "# ";
        for (char ch : rows[i])
            cout << ch;
        cout << endl;
    }

    return 0;
}
