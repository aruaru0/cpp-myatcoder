#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    set<string> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            m.insert(s[i] + s[j]);
        }
    }

    cout << m.size() << endl;
    return 0;
}