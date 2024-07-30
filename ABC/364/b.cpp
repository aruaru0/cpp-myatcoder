#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int h, w;
    cin >> h >> w;
    int si, sj;
    cin >> si >> sj;
    si--, sj--;

    vector<string> c(h);
    rep(i, h) cin >> c[i];
    string x;
    cin >> x;

    for (auto e : x)
    {
        int ni = si, nj = sj;
        switch (e)
        {
        case 'L':
            nj--;
            break;
        case 'R':
            nj++;
            break;
        case 'U':
            ni--;
            break;
        case 'D':
            ni++;
            break;
        }
        if (ni < 0 || ni >= h || nj < 0 || nj >= w)
            continue;
        if (c[ni][nj] == '#')
            continue;
        si = ni, sj = nj;
    }

    cout << si + 1 << " " << sj + 1 << endl;
}