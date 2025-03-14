#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;

    vector<int> X(N), Y(N);
    vector<vector<pair<int, int>>> blocks(W + 1);

    for (int i = 0; i < N; i++)
    {
        cin >> X[i] >> Y[i];
        blocks[X[i]].emplace_back(Y[i], i);
    }

    vector<int> cnt(N);
    vector<int> disappear(N + 1, -1);

    for (int x = 1; x <= W; x++)
    {
        sort(blocks[x].begin(), blocks[x].end());
        for (size_t j = 0; j < blocks[x].size(); j++)
        {
            cnt[blocks[x][j].second] = j;
            disappear[j] = max(disappear[j], blocks[x][j].first);
        }
        disappear[blocks[x].size()] = int(1e9 + 10);
    }

    for (int i = 0; i < N; i++)
    {
        disappear[i + 1] = max(disappear[i + 1], disappear[i] + 1);
    }

    int Q;
    cin >> Q;
    while (Q--)
    {
        int T, A;
        cin >> T >> A;
        A--;
        cout << (T < disappear[cnt[A]] ? "Yes" : "No") << '\n';
    }

    return 0;
}