#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        os << "(" << v[i].num << "," << v[i].cnt << ")";
    }
    return os;
}

struct P
{
    int num = 0, cnt = 0;
};

int main()
{
    string s;
    cin >> s;

    vector<P> a;
    int prev = s[0] - '0';
    int cnt = 1;
    for (int i = 1; i < s.size(); i++)
    {
        int cur = s[i] - '0';
        if (prev == cur)
        {
            cnt++;
        }
        else
        {
            a.push_back(P{prev, cnt});
            prev = cur;
            cnt = 1;
        }
    }

    a.push_back(P{prev, cnt});

    ll ans = 0;
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i].num + 1 == a[i + 1].num)
        {
            ans += min(a[i].cnt, a[i + 1].cnt);
        }
    }

    cout << ans << endl;
}