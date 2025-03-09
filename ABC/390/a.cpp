#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i < 5; i++)
    {
        swap(a[i], a[i - 1]);
        bool ok = true;
        for (int j = 0; j < 5; j++)
        {
            if (a[j] != j + 1)
            {
                ok = false;
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
        swap(a[i], a[i - 1]);
    }

    cout << "No" << endl;
    return 0;
}