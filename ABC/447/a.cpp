#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int d = n - m;

    if (d + 1 >= m)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}