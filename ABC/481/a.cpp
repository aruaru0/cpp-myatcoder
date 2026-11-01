#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    for (auto &c : s)
    {
        if (c == 'o')
            cnt++;
    }

    if (cnt % 2 == 0)
    {
        cout << "even" << endl;
    }
    else
    {
        cout << "odd" << endl;
    }

    return 0;
}