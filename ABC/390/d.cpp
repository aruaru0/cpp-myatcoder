#include <bits/stdc++.h>
using namespace std;

int n;
long long a[12];
long long s[12];
long long val;
unordered_set<long long> st;

void dfs(int idx, int sz)
{
    for (int i = 0; i <= sz; i++)
    {
        val ^= s[i];
        s[i] += a[idx];
        val ^= s[i];
        if (idx == n - 1)
            st.insert(val);
        else if (i < sz)
            dfs(idx + 1, sz);
        else
            dfs(idx + 1, sz + 1);
        val ^= s[i];
        s[i] -= a[idx];
        val ^= s[i];
    }
    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
        s[i] = 0;
    val = 0;
    dfs(0, 0);
    cout << ((int)(st.size())) << endl;
    return 0;
}
