#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int x;
    cin >> x;
    x--;

    string t;
    cin >> t;

    if (s[x] == t)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}