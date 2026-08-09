#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;

    int max_col = 0;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        mp[c]++;
        max_col = max(max_col, mp[c]);
    }

    cout << n - max_col << endl;
}