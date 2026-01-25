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
    cin >> q;

    bool play = false;
    int vol = 0;

    rep(i, q)
    {
        int a;
        cin >> a;
        switch (a)
        {
        case 1:
            vol++;
            break;
        case 2:
            vol = max(0, vol - 1);
            break;
        case 3:
            play = !play;
            break;
        }

        if (play && vol >= 3)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
