#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> mp;
    rep(i, m)
    {
        int b;
        cin >> b;
        mp[b]++;
    }

    vector<int> ans;
    for (auto e : a)
    {
        if (mp[e] != 0)
        {
            mp[e]--;
        }
        else
        {
            ans.push_back(e);
        }
    }

    for (auto e : ans)
        cout << e << " ";
    cout << endl;
}