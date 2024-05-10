#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m[s]++;
    }

    if (m["Perfect"] == n)
    {
        cout << "All Perfect " << endl;
    }
    else if (m["Perfect"] + m["Great"] == n)
    {
        cout << "Full Combo " << endl;
    }
    else
    {
        cout << "Failed " << endl;
    }
}