#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;
    vector<int> A(N);
    for (int &x : A)
        cin >> x;

    int64 ans = 0;
    for (int k = 1; k <= 30; ++k)
    {
        int M = 1 << k; // 2^k
        unordered_map<int, int> freq;
        freq.reserve(N * 2);

        for (int x : A)
            ++freq[x & (M - 1)]; // 下位 k ビット

        int64 pairs = 0;
        for (auto &[r, f] : freq)
        {
            int s = (M - r) & (M - 1); // 相手の剰余
            if (r < s)
            {
                auto it = freq.find(s);
                if (it != freq.end())
                    pairs += 1LL * f * it->second;
            }
            else if (r == s)
            {
                pairs += 1LL * f * (f - 1) / 2;
            }
            // r > s は既に数えている
        }
        ans += pairs;
    }
    cout << ans << '\n';
    return 0;
}
