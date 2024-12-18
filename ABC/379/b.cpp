#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    s += 'X';
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'X')
        {
            ans += cnt / k;
            cnt = 0;
        }
        else
        {
            cnt++;
        }
    }
    cout << ans << endl;
}