#include <iostream>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;

    int tot = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '@')
        {
            tot--;
        }
    }

    cout << tot + d << endl;

    return 0;
}