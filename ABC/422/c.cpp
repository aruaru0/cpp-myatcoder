#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        cout << min((a + b + c) / 3, min(a, c)) << endl;
    }
}