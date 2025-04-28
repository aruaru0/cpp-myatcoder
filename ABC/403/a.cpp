#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (i % 2 == 0)
        {
            tot += a;
        }
    }

    cout << tot << endl;

    return 0;
}