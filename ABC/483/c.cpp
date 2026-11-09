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

struct Person
{
    int cnt;
    int idx;
    Person() : cnt(-1), idx(-1) {};
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<map<int, int>> sel(n);
    vector<int> p(n);

    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a -= 1, b -= 1;
        p[a]++;
        sel[a][b]++;
    }

    Person top1, top2;
    rep(i, n)
    {
        if (top1.cnt < p[i])
        {
            top2 = top1;
            top1.cnt = p[i];
            top1.idx = i;
        }
        else if (top2.cnt < p[i])
        {
            top2.cnt = p[i];
            top2.idx = i;
        }
    }

    rep(i, n)
    {
        Person top = top1;
        if (top.idx == i)
        {
            top = top2;
        }
        for (auto [idx, cnt] : sel[i])
        {
            int new_cnt = p[idx] + cnt;
            if (top.cnt == new_cnt && top.idx > idx)
            {
                top.cnt = new_cnt;
                top.idx = idx;
            }
            else if (top.cnt < new_cnt)
            {
                top.cnt = new_cnt;
                top.idx = idx;
            }
        }
        cout << top.idx + 1 << endl;
    }

    return 0;
}
