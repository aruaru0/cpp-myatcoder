#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> inQueue(H, vector<bool>(W, false));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    rep(i, H)
    {
        pq.push(tuple{A[i][0], i, 0});
        pq.push(tuple{A[i][W - 1], i, W - 1});
        inQueue[i][0] = true;
        inQueue[i][W - 1] = true;
    }
    for (int i = 1; i < W - 1; i++)
    {
        pq.push(tuple{A[0][i], 0, i});
        pq.push(tuple{A[H - 1][i], H - 1, i});
        inQueue[0][i] = true;
        inQueue[H - 1][i] = true;
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    vector<vector<bool>> used(H, vector<bool>(W, false));

    int tot = H * W;
    for (int y = 1; y <= Y; y++)
    {
        // cout << get<0>(pq.top()) << endl;
        while (!pq.empty() && get<0>(pq.top()) <= y)
        {
            auto t = pq.top();
            pq.pop();
            int x = get<2>(t);
            int y = get<1>(t);
            if (used[y][x] == false)
            {
                tot--;
            }
            used[y][x] = true;
            for (int i = 0; i < 4; i++)
            {
                int px = x + dx[i];
                int py = y + dy[i];
                if (px < 0 || px >= W || py < 0 || py >= H)
                    continue;
                if (inQueue[py][px])
                    continue;
                inQueue[py][px] = true;
                pq.push(tuple{A[py][px], py, px});
            }
        }
        cout << tot << endl;
    }
}
