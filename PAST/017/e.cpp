#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;

    cin >> s;

    auto cur = s[0];
    int cnt = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == cur)
        {
            cnt++;
        }
        else
        {
            cout << cur << " " << cnt << " ";
            cnt = 1;
            cur = s[i];
        }
    }
    cout << cur << " " << cnt << endl;
}