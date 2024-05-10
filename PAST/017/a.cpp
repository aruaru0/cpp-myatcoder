#include <iostream>

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    if (20 * h * h > w * 10000)
    {
        cout << "A" << endl;
    }
    else if (25 * h * h <= w * 10000)
    {
        cout << "C" << endl;
    }
    else
    {
        cout << "B" << endl;
    }
}