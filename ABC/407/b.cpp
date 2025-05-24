#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    int tot = 0, cnt = 0;
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
        {
            if (i + j >= x || abs(i - j) >= y)
            {
                cnt++;
            }
            tot++;
        }

    cout << setprecision(15) << 1.0 * cnt / tot << endl;

    return 0;
}