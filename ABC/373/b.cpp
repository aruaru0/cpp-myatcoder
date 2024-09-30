#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;
    vector<int> v(26);
    rep(i, s.size())
    {
        v[s[i] - 'A'] = i;
    }

    int tot = 0;
    for (int i = 1; i < 26; i++)
    {
        tot += abs(v[i] - v[i - 1]);
    }
    cout << tot << endl;
}