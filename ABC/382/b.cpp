#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, d;

    cin >> n >> d;
    string s;

    cin >> s;

    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '@')
        {
            a.push_back(i);
        }
    }
    for (int i = a.size() - d; i < a.size(); i++)
    {
        s[a[i]] = '.';
    }

    cout << s << endl;
}