#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;

    cin >> s;

    int cnt = -1;
    vector<int> a;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '|')
        {
            if (cnt > 0)
            {
                a.push_back(cnt);
            }
            cnt = 0;
        }
        else
        {
            cnt++;
        }
    }

    for (auto e : a)
    {
        cout << e << ' ';
    }
    cout << endl;
}