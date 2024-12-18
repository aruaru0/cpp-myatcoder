#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lb(const vector<int> &v, int x)
{
    return lower_bound(begin(v), end(v), x) - begin(v);
}
int sz(const vector<int> &v) { return v.size(); }

int main()
{
    int N, Q;
    string S;
    cin >> N >> Q >> S;

    vector<int> idx1, idx2, idxs;
    for (int i = 0; i < N; i++)
    {
        (S[i] == '1' ? idx1 : S[i] == '2' ? idx2
                                          : idxs)
            .push_back(i);
    }
    while (Q--)
    {
        int l, r;
        cin >> l >> r;
        --l;

        // 1, 2 の長さが len である 11/22 文字列が存在するか？
        auto f = [&](int len) -> bool
        {
            if (len == 0)
            {
                // / を発見
                int j = lb(idxs, l);
                if (j >= sz(idxs))
                    return false;
                return idxs[j] < r;
            }
            // 1 を発見
            int i = lb(idx1, l);
            if (i + len - 1 >= sz(idx1))
                return false;
            // / を発見
            int j = lb(idxs, idx1[i + len - 1]);
            if (j >= sz(idxs))
                return false;
            // 2 を発見
            int k = lb(idx2, idxs[j]);
            if (k + len - 1 >= sz(idx2))
                return false;
            return idx2[k + len - 1] < r;
        };

        int ok = -1, ng = N + 1;
        while (ok + 1 < ng)
        {
            int m = (ok + ng) / 2;
            (f(m) ? ok : ng) = m;
        }
        cout << (ok == -1 ? 0 : ok * 2 + 1) << "\n";
    }
}
