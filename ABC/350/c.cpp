#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using PP = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    rep(i, n)
    {
        cin >> a[i];
        a[i]--;
    }
    vector<int> pos(n);
    rep(i, n)
    {
        pos[a[i]] = i;
    }

    vector<PP> ans;
    rep(i, n)
    {
        if (a[i] != i)
        {
            int j = pos[i];
            ans.push_back(PP(min(i, j), max(i, j)));
            swap(a[i], a[j]);
            pos[a[j]] = j;
            pos[a[i]] = i;
        }
    }

    cout << ans.size() << endl;
    for (auto p : ans)
    {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}