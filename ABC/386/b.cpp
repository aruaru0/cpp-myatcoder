#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int cnt = s.size();
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '0' && s[i + 1] == '0')
        {
            i++;
            cnt--;
        }
    }

    cout << cnt << endl;
}