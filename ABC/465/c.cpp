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
    int n;
    cin >> n;
    string s;
    cin >> s;

    deque<int> dq;
    int dirc = 0;
    rep(i, n)
    {
        if (dirc == 0)
        {
            dq.push_back(i + 1);
        }
        else
        {
            dq.push_front(i + 1);
        }
        if (s[i] == 'o')
            dirc ^= 1;
    }

    rep(i, n)
    {
        if (dirc == 0)
        {
            cout << dq.front() << " ";
            dq.pop_front();
        }
        else
        {
            cout << dq.back() << " ";
            dq.pop_back();
        }
    }
    cout << endl;
    return 0;
}
