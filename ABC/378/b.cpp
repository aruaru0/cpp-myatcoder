#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> q(n), r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> q[i] >> r[i];
    }

    int Q;
    cin >> Q;
    for (int qi = 0; qi < Q; qi++)
    {
        int t, d;
        cin >> t >> d;
        t--;
        int diff = (r[t] - d) % q[t];
        if (diff < 0)
            diff += q[t];
        cout << d + diff << endl;
    }
}