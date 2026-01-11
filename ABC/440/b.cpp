#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<P> p(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        p[i] = {t, i + 1};
    }

    sort(p.begin(), p.end());
    for (int i = 0; i < 3; i++)
    {
        cout << p[i].second << " ";
    }
    cout << endl;
}