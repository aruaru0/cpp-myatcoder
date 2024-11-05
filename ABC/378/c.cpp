#include <iostream>
#include <map>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    vector<int> ans;
    map<int, int> mp;

    rep(i, n)
    {
        int x;
        cin >> x;
        if (mp.find(x) != mp.end())
        {
            ans.push_back(mp[x]);
        }
        else
        {
            ans.push_back(-1);
        }
        mp[x] = i + 1;
    }

    for (auto e : ans)
        cout << e << " ";
    cout << endl;
}