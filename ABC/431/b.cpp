#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    int x, n;
    cin >> x >> n;
    vector<int> w(n);

    rep(i, n)
    {
        cin >> w[i];
    }

    vector<int> m(n, 0);

    int q;
    cin >> q;
    rep(qi, q)
    {
        int i;
        cin >> i;
        i--;
        if (m[i] == 0)
        {
            x += w[i];
            m[i] = w[i];
        }
        else
        {
            x -= m[i];
            m[i] = 0;
        }
        cout << x << endl;
    }
}