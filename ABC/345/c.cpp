#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    cin >> s;

    vector<int> cnt(26);

    int pls = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int v = s[i] - 'a';
        cnt[v]++;
        if (cnt[v] >= 2)
        {
            pls = 1;
        }
    }

    long long tot = pls;
    int n = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        int v = s[i] - 'a';
        tot += n - cnt[v];
        cnt[v]--;
        n--;
    }

    cout << tot << endl;

    return 0;
}