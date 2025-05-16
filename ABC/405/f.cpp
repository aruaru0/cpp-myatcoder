#include <bits/stdc++.h>
using namespace std;
struct Fenwick
{
    int n;
    vector<int> bit;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void add(int idx, int val)
    {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }
    int sum(int idx)
    {
        int s = 0;
        for (; idx > 0; idx -= idx & -idx)
            s += bit[idx];
        return s;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> seg(M);
    const int SZ = 2 * N;
    vector<int> endCnt(SZ + 1, 0);
    for (auto &[a, b] : seg)
    {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        endCnt[a]++;
        endCnt[b]++;
    }
    /* 累積和 */
    vector<int> pref(SZ + 1);
    for (int i = 1; i <= SZ; i++)
        pref[i] = pref[i - 1] + endCnt[i];

    /* 右端でソート */
    sort(seg.begin(), seg.end(),
         [](auto &l, auto &r)
         { return l.second < r.second; });

    int Q;
    cin >> Q;
    struct Query
    {
        int C, D, idx;
    };
    vector<Query> qs(Q);
    for (int i = 0; i < Q; i++)
    {
        int c, d;
        cin >> c >> d;
        if (c > d)
            swap(c, d);
        qs[i] = {c, d, i};
    }
    sort(qs.begin(), qs.end(),
         [](auto &l, auto &r)
         { return l.D < r.D; });

    Fenwick bit(SZ);
    vector<long long> ans(Q);
    int p = 0;
    for (auto &q : qs)
    {
        while (p < M && seg[p].second < q.D)
        {
            bit.add(seg[p].first, 1);
            ++p;
        }
        long long insideEnd = pref[q.D - 1] - pref[q.C];
        long long insideChord = bit.sum(q.D - 1) - bit.sum(q.C);
        ans[q.idx] = insideEnd - 2 * insideChord;
    }
    for (auto x : ans)
        cout << x << "\n";
    return 0;
}
