#include <iostream>
#include <set>

using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;

    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

    set<P> st;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> y >> x;
        y--;
        x--;
        for (int j = 0; j < 8; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            {
                continue;
            }
            st.insert(P(nx, ny));
        }
        st.insert(P(x, y));
    }

    ll ans = (ll)n * n;

    cout << ans - st.size() << endl;
}