#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int ans = 0;

    for (int i = 1; i <= N; i++)
    {
        int s = i % 2 == 0 ? 1 : -1;
        ans += s * i * i * i;
    }

    cout << ans << endl;
}