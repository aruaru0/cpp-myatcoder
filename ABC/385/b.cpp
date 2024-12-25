#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    vector<string> s(h);
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }
    int cnt = 0;
    string T;
    cin >> T;

    x--;
    y--;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    vector<vector<bool>> used(h, vector<bool>(w, false));

    for (auto e : T)
    {
        int idx = 0;
        if (e == 'U')
        {
            idx = 0;
        }
        else if (e == 'D')
        {
            idx = 1;
        }
        else if (e == 'L')
        {
            idx = 2;
        }
        else
        {
            idx = 3;
        }
        int nx = x + dx[idx];
        int ny = y + dy[idx];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w)
        {
            continue;
        }
        if (s[nx][ny] == '#')
        {
            continue;
        }
        if (s[nx][ny] == '@' && used[nx][ny] == false)
        {
            cnt++;
        }
        used[nx][ny] = true;
        x = nx;
        y = ny;
    }

    cout << x + 1 << " " << y + 1 << " " << cnt << endl;
    return 0;
}