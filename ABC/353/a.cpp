#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x;
    cin >> x;
    for (int i = 1; i < n; i++)
    {
        int h;
        cin >> h;
        if (x < h)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}