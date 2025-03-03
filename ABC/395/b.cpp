#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; (i) < (n); ++(i))

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> s(n, vector<char>(n, 0));
    rep(i, n)
    {
        int j = n - i;
        char col = '#';
        if (i % 2 == 1)
            col = '.';
        for (int h = i; h < j; h++)
        {
            for (int w = i; w < j; w++)
            {
                s[h][w] = col;
            }
        }
    }

    rep(i, n)
    {
        rep(j, n)
        {
            cout << s[i][j];
        }
        cout << endl;
    }
}