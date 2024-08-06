#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int mx1 = -1, mx2;
    int idx1 = -1, idx2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x > mx1)
        {
            mx2 = mx1;
            idx2 = idx1;
            mx1 = x;
            idx1 = i;
        }
        else if (x > mx2)
        {
            mx2 = x;
            idx2 = i;
        }
    }

    cout << idx2 + 1 << endl;
}