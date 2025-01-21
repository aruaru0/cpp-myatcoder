#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int q;
    cin >> q;
    ll now = 0;
    vector<ll> x;
    int id = 0;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            ll l;
            cin >> l;
            x.push_back(now);
            now += l;
        }
        else if (t == 2)
        {
            id++;
        }
        else
        {
            int k;
            cin >> k;
            k--;
            cout << x[id + k] - x[id] << endl;
        }
    }
}