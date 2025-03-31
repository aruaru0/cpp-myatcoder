#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
            cnt++;
    }

    cout << cnt << endl;
}