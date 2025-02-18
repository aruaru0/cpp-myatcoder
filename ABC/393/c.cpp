#include <iostream>
#include <set>

using namespace std;
using P = pair<int, int>;

int main()
{
    int n, m;

    cin >> n >> m;
    int cnt = 0;
    set<P> s;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
        {
            swap(u, v);
        }
        if (u == v)
        {
            cnt++;
        }
        else if (s.find(P(u, v)) != s.end())
        {
            cnt++;
        }
        s.insert(P(u, v));
    }

    cout << cnt << endl;
}