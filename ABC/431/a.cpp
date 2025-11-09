#include <iostream>

using namespace std;

int main()
{
    int h, b;
    cin >> h >> b;

    cout << max(0, h - b) << endl;
}