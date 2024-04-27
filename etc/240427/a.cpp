#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mp[a]++;
    }

    int ans = mp.size();
    for (auto e : mp)
    {
        if (m > 0 && e.second > 1)
        {
            ans += min(m, e.second - 1);
            m -= e.second - 1;
        }
    }
    cout << ans << endl;
}