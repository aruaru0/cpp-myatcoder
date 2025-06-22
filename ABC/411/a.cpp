#include <iostream>

using namespace std;

int main()
{
    string P;
    int L;

    cin >> P >> L;

    if (P.size() >= L)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}