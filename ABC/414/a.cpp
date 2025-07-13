#include <iostream>

using namespace std;

int main()
{
    int n, l, r;
    cin >> n >> l >> r;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x <= l && r <= y)
            cnt++;
    }
    cout << cnt << endl;
}