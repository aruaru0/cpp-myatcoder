#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> m;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
        {
            m.push_back(i + 1);
        }
    }

    for (int i = 0; i < m.size(); i += 2)
    {
        cout << m[i] << "," << m[i + 1] << endl;
    }
}