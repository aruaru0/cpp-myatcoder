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

int main()
{
    int q;
    priority_queue<int, vector<int>, greater<int>> que;
    cin >> q;

    rep(qi, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            que.push(x);
        }
        else
        {
            cout << que.top() << endl;
            que.pop();
        }
    }
    return 0;
}
