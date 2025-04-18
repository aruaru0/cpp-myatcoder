#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> score(n, 0);
    vector<int> last(n, -1);

    for (int i = 0; i < m; i++)
    {
        int e;
        cin >> e;
        if (e == 1)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            last[y] = x;
        }
        else
        {
            int x;
            cin >> x;
            x--;
            score[x]--;
            if (last[x] != -1)
            {
                score[last[x]]++;
            }
            last[x] = -1;
        }
    }

    for (auto e : score)
    {
        cout << e << " ";
    }
    cout << endl;
}