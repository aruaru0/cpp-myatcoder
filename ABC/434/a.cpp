#include <iostream>

using namespace std;

int main()
{
    int W, B;

    cin >> W >> B;

    int n = W * 1000 / B;
    cout << n + 1 << endl;
}