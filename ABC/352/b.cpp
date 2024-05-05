#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    vector<int> ans;
    int idx = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (idx == s.size())
            break;
        if (t[i] == s[idx])
        {
            ans.push_back(i + 1);
            idx++;
        }
    }

    for (auto e : ans)
    {
        cout << e << " ";
    }
    cout << endl;
}