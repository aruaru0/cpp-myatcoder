#include <iostream>

using namespace std;

int main()
{
    int r;
    cin >> r;
    int target = (r / 100 + 1) * 100;

    cout << target - r << endl;
}