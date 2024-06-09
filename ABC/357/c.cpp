#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    int bit = 1;
    rep(i, n) bit *= 3;

    vector<vector<int>> p(bit, vector<int>(bit, 1));

    int v = 1;
    rep(level, n)
    {
        rep(i, bit)
        {
            rep(j, bit)
            {
                int x = i / v;
                int y = j / v;
                if (x % 3 == 1 && y % 3 == 1)
                {
                    p[i][j] = 0;
                }
            }
        }
        v *= 3;
    }

    rep(i, bit)
    {
        rep(j, bit)
        {
            if (p[i][j] == 1)
                cout << "#";
            else
                cout << ".";
        }
        cout << endl;
    }
}