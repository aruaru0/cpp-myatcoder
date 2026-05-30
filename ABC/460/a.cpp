#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int tot = 0;
    while (m != 0)
    {
        tot++;
        m = n % m;
    }
    cout << tot << endl;
}