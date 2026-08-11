#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> p1(n);
    vector<int> p2(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        p1[i] = x;
        p2[x] = i;
    }

    for (int qi = 0; qi < q; qi++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            x--, y--;
            int a = p1[x], b = p1[y];
            swap(p1[x], p1[y]);
            swap(p2[a], p2[b]);
        }
        else
        {
            swap(p1, p2);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << p1[i] + 1 << " ";
    }
    cout << endl;
}