#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;

    ll tot = 0;
    string s;
    for (int i = 0; i < n; i++)
    {
        char e;
        ll l;
        cin >> e >> l;
        tot += l;
        if (tot > 100)
        {
            cout << "Too Long" << endl;
            return 0;
        }
        for (int j = 0; j < l; j++)
        {
            s += e;
        }
    }
    cout << s << endl;
}