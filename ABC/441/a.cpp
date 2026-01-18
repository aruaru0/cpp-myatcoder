#include <iostream>

using namespace std;

int main()
{
    int P, Q;
    cin >> P >> Q;
    int X, Y;
    cin >> X >> Y;

    if (P <= X && X < P + 100 && Q <= Y && Y < Q + 100)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}