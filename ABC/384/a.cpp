#include <iostream>

using namespace std;

int main()
{
    int n;
    char c1, c2;
    cin >> n >> c1 >> c2;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        // cout << s[i] << "->" << c1 << endl;
        if (s[i] != c1)
            cout << c2;
        else
            cout << s[i];
    }

    cout << endl;
    return 0;
}