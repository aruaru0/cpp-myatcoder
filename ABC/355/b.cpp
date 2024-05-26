#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    map<int, int> p;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        p[x] = 0;
    }
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        p[x] = 1;
    }

    int cur = -1;
    for (int i = 0; i <= 200; i++)
    {
        if (p.find(i) == p.end()) // 見つからない場合
        {
            continue;
        }
        // cout << cur << " " << p[i] << endl;
        if (p[i] == 0 && cur == p[i])
        {
            cout << "Yes" << endl;
            return 0;
        }
        cur = p[i];
    }
    cout << "No" << endl;
}