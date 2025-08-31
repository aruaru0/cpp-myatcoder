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

    ll odd = 0, even = 0;
    int pos = 0;
    for (int i = 0; i < n * 2; i++)
    {
        if (s[i] == 'A')
        {
            odd += abs(2 * pos + 1 - i);
            even += abs(2 * pos - i);
            pos++;
        }
    }

    cout << min(odd, even) << endl;

    return 0;
}
