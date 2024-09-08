#include <iostream>

using namespace std;

int main()
{
    int L, R;
    cin >> L >> R;

    if (L == 1 && R == 0)
    {
        cout << "Yes" << endl;
        return 0;
    }
    else if (L == 0 && R == 1)
    {
        cout << "No" << endl;
        return 0;
    }

    cout << "Invalid" << endl;
}