#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    vector<int> a;

    rep(i, 4)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    int cnt = 0;
    rep(i, 3)
    {
        if (a[i] == a[i + 1])
        {
            cnt++;
            i++;
        }
    }
    cout << cnt << endl;
}