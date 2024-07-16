#include <iostream>

using namespace std;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    string c;
    cin >> c;
    int ans;
    if (c == "Red")
    {
        ans = min(g, b);
    }
    else if (c == "Green")
    {
        ans = min(r, b);
    }
    else
    {
        ans = min(r, g);
    }
    cout << ans << endl;
}