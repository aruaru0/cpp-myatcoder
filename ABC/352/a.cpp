#include <iostream>
using namespace std;

int main()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    if (x > y)
    {
        swap(x, y);
    }
    if (x <= z && z <= y)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}