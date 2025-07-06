#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        tot += a;
    }

    if (tot <= m)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}