#include <iostream>

int main()
{
    using namespace std;
    string s;
    cin >> s;

    for (auto &c : s)
    {
        if (c != 'A')
            c = '.';
    }
    cout << s << endl;
}