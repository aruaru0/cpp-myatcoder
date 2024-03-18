#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    cin >> s;

    int n = s.size();
    int pls = 0;
    vector<int> cnt(26);

    for (int i = 0; i < n; i++)
    {
        int v = s[i] - 'a';
        cnt[v]++;
        if (cnt[v] > 1)
        {
            pls = 1;
        }
    }

    int tot = pls;
    for (int i = 0; i < n; i++)
    {
        int v = s[i] - 'a';
        tot += (n - i) - cnt[v];
        cnt[v]--;
    }

    cout << tot << endl;

    return 0;
}