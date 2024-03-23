#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int x0, x1, y0, y1;
    cin >> x0 >> y0;
    cin >> x1 >> y1;

    int diff = abs(x0 - x1) + abs(y0 - y1);

    cout << diff + 1 << endl;

    return 0;
}