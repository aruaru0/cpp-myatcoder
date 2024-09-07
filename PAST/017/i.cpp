#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N;
    cin >> N;

    vector<string> S(N);
    map<string, int> mp;

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
        mp[S[i]]++;
    }

    long long ans = 0;

    auto pat = [&](auto pat, string s) -> vector<string>
    {
        vector<string> ret;
        set<string> st;
        for (int bit = 1; bit < 1 << s.size(); bit++)
        {
            string t = "";
            for (int i = 0; i < s.size(); i++)
            {
                if ((bit >> i) % 2)
                    t += s[i];
            }
            if (st.count(t))
                continue;
            st.insert(t);
            ret.emplace_back(t);
        }
        return ret;
    };

    for (int i = 0; i < N; i++)
    {
        auto ts = pat(pat, S[i]);
        for (int j = 0; j < ts.size(); j++)
        {
            if (mp.count(ts[j]))
                ans += mp[ts[j]];
        }
    }

    cout << ans << endl;

    return 0;
}
