#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// coutにvector<int>を表示させる
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
    }
    os << "]";
    return os;
}

struct X
{
    int size, idx;
};

int main()
{
    int H, W, N;
    cin >> H >> W >> N;

    map<int, deque<X>> mp_h;
    map<int, deque<X>> mp_w;

    rep(i, N)
    {
        int x, y;
        cin >> x >> y;
        mp_h[x].push_back({y, i});
        mp_w[y].push_back({x, i});
    }

    set<int> used;

    vector<P> ans(N);

    int ph = 0, pw = 0;
    rep(i, N)
    {
        while (mp_h[H].size() > 0 && used.find(mp_h[H][0].idx) != used.end())
        {
            mp_h[H].pop_front();
        }
        while (mp_w[W].size() > 0 && used.find(mp_w[W][0].idx) != used.end())
        {
            mp_w[W].pop_front();
        }

        if (mp_h[H].size() != 0)
        {
            ans[mp_h[H][0].idx] = {ph, pw};
            pw += mp_h[H][0].size;
            used.insert(mp_h[H][0].idx);
            W -= mp_h[H][0].size;
        }
        else if (mp_w[W].size() != 0)
        {
            ans[mp_w[W][0].idx] = {ph, pw};
            ph += mp_w[W][0].size;
            used.insert(mp_w[W][0].idx);
            H -= mp_w[W][0].size;
        }
    }

    rep(i, N)
    {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }

    return 0;
}
