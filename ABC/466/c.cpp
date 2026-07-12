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

    int r = 1, cnt = 0;
    for (int l = 1; l <= n; l++)
    {
        if (l == r)
            r++;
        while (r <= n)
        {
            std::cout << "? " << l << " " << r << endl;
            string s;
            cin >> s;
            if (s == "Yes")
                r++;
            else
                break;
        }
        cnt += (r - l - 1);
    }

    std::cout << "! " << cnt << endl;

    return 0;
}
