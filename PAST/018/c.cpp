#include <iostream>

using namespace std;

int main()
{
    int b1, r1, b2, r2, t;
    cin >> b1 >> r1 >> b2 >> r2;
    cin >> t;

    int cnt = 0;
    for (int i = 0; i < t; i++)
    {
        bool signal1 = false;
        if ((i % (b1 + r1)) < b1)
        {
            signal1 = true;
        }
        bool signal2 = false;
        if ((i % (b2 + r2)) < b2)
        {
            signal2 = true;
        }
        if (signal1 && signal2)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}