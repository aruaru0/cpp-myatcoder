#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int tot_a = 0, tot_b = b, tot_c = c;
    for (int i = 0; i < 12; i++)
    {
        int x;
        cin >> x;
        tot_a += max(0, x - 3) * a;
        tot_b += max(0, x - 50) * a;
    }

    cout << min(tot_a, min(tot_b, tot_c)) << endl;
}