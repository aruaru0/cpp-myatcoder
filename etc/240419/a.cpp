#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

typedef struct
{
    int x, y;
    int p;
} Point;

int main()
{
    int n;
    cin >> n;
    vector<Point> v(n);
    vector<ll> h(210000), w(210000);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].x >> v[i].y >> v[i].p;
        h[v[i].y] += v[i].p;
        w[v[i].x] += v[i].p;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, h[v[i].y] + w[v[i].x] - v[i].p);
    }

    cout << ans << endl;
}