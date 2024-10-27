#include <iostream>

using namespace std;

int main()
{
    string s;

    cin >> s;
    int bit = 0;
    for (auto c : s)
    {
        if (c == 'A')
        {
            bit |= 1;
        }
        else if (c == 'B')
        {
            bit |= 2;
        }
        else
        {
            bit |= 4;
        }
    }
    if (bit == 7)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}