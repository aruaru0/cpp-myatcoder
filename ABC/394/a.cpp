#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    for (auto c : s)
    {
        if (c == '2')
        {
            cout << c;
        }
    }
    cout << endl;
}