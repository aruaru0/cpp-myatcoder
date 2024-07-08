#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int g, h, i, j, k, l;
    cin >> g >> h >> i >> j >> k >> l;

    int x = min(d, j) - max(a, g);
    int y = min(e, k) - max(b, h);
    int z = min(f, l) - max(c, i);

    if (x * y * z > 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}