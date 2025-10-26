#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        if (i < m)
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << "Too Many Requests" << endl;
        }
    }
}