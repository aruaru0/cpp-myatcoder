#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<vector<ll>> grid(3, vector<ll>(3, 0));
vector<vector<ll>> pos(3, vector<ll>(3, 0));

int f(int x)
{
    if (x % 2 != 0)
    {
        return 1;
    }
    return 2;
}

bool checkDir(int x, int y, int dx, int dy)
{
    int now = pos[x][y];
    if (now == 0)
        return false;
    rep(i, 3)
    {
        if (now != pos[x + i * dx][y + i * dy])
        {
            return false;
        }
    }
    return true;
}

bool check()
{
    if (checkDir(0, 0, 0, 1) || checkDir(0, 0, 1, 0) || checkDir(0, 0, 1, 1))
    {
        return true;
    }
    if (checkDir(1, 0, 0, 1) || checkDir(2, 0, 0, 1))
    {
        return true;
    }
    if (checkDir(0, 1, 1, 0) || checkDir(0, 2, 1, 0))
    {
        return true;
    }
    if (checkDir(2, 0, -1, 1))
    {
        return true;
    }
    return false;
}

bool solve(int x)
{
    if (x == 10)
    {
        ll tak = 0, aok = 0;
        rep(i, 3) rep(j, 3)
        {
            if (pos[i][j] == 1)
            {
                tak += grid[i][j];
            }
            else
            {
                aok += grid[i][j];
            }
        }
        if (aok > tak)
        {
            return true;
        }
        return false;
    }
    rep(i, 3) rep(j, 3)
    {
        if (pos[i][j] == 0)
        {
            pos[i][j] = f(x);
            if (check())
            {
                pos[i][j] = 0;
                return true;
            }
            pos[i][j] = 0;
        }
    }

    rep(i, 3) rep(j, 3)
    {
        if (pos[i][j] == 0)
        {
            pos[i][j] = f(x);
            if (!solve(x + 1))
            {
                pos[i][j] = 0;
                return true;
            }
            pos[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    rep(i, 3) rep(j, 3) cin >> grid[i][j];

    if (solve(1))
    {
        cout << "Takahashi" << endl;
    }
    else
    {
        cout << "Aoki" << endl;
    }
}