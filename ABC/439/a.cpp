#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 1 << n;

    ans -= 2 * n;
    cout << ans << endl;
    return 0;
}