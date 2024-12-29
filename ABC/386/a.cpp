#include <iostream>
#include <map>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    map<int, int> mp;

    rep(i, 4)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    if (mp.size() == 2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}