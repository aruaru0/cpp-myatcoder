#include <iostream>

using namespace std;

int main()
{
    char c[3];
    cin >> c[0] >> c[1] >> c[2];

    std::sort(c, c + 3);

    cout << c[2] << c[1] << c[0] << endl;
}