#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;
    int mx = -1e9;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mx = max(mx, a);
    }

    if (mx > 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}