#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> trie(310000, vector<int>(26, -1));
// vector<int> w(310000, 0);

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    int l;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        l += s[i].size();
    }

    int nx = 1;

    vector<int> w;
    w.push_back(0);

    for (auto e : s)
    {
        int cur = 0;
        for (auto c : e)
        {
            int d = c - 'a';
            if (trie[cur][d] == -1)
            {
                trie[cur][d] = nx;
                nx++;
                w.push_back(0);
            }
            cur = trie[cur][d];
            w[cur]++;
        }
    }

    long long ans = 0;
    for (auto x : w)
    {
        ans += (long long)x * (x - 1) / 2;
    }
    cout << ans << endl;
}