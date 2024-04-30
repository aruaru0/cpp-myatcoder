#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<ll> ans;
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        while (ans.size() > 0 && ans.back() == cur)
        {
            ans.pop_back();
            cur++;
        }
        ans.push_back(cur);
    }
    // for (auto e : ans)
    //     cout << e << " ";
    // cout << endl;
    cout << ans.size() << endl;
}