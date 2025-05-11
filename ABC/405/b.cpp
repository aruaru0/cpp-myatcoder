#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> p;
    rep(i, n)
    {
        cin >> a[i];
        if (a[i] <= m)
            p[a[i]]++;
    }

    if (p.size() != m)
    {
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        p[a[i]]--;
        cnt++;
        if (p[a[i]] == 0)
            break;
    }
    cout << cnt << endl;
    return 0;
}