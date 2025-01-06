#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;

    int cnt = 0;

    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            if (i * j != x)
            {
                cnt += i * j;
            }
        }

    cout << cnt << endl;
}