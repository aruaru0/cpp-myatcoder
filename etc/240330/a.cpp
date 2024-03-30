#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int a, b;
    cin >> a >> b;
    set<int> p0, p1;
    rep(i, a)
    {
        int x;
        cin >> x;
        p0.insert(x);
    }
    rep(i, b)
    {
        int x;
        cin >> x;
        p1.insert(x);
    }

    vector<int> pos = {7, 8, 9, 0, -1, 4, 5, 6, -2, 2, 3, -3, 1};
    for (auto e : pos)
    {
        if (e < 0)
        {
            cout << endl;
            rep(i, -e)
            {
                cout << " ";
            }
        }
        else
        {
            if (p0.find(e) != p0.end())
            {
                cout << ". ";
            }
            else if (p1.find(e) != p1.end())
            {
                cout << "o ";
            }
            else
            {
                cout << "x ";
            }
        }
    }
    cout << endl;
}