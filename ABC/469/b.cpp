#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "x" + s + "x";

    int cnt = 0;
    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i - 1] == 'x' && s[i] == 'x' && s[i + 1] == 'x')
            cnt++;
    }
    cout << cnt << endl;
}