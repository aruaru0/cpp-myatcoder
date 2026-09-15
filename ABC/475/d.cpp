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

vector<string> primes(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    vector<string> res;
    for (int i = 0; i <= n; i++)
    {
        if (is_prime[i])
        {
            res.push_back(to_string(i));
        }
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    vector<string> p = primes(9999999);

    auto check = [](string s, string t) -> bool
    {
        if (s.size() != t.size())
            return false;

        map<char, int> ms, mt;
        for (int i = 0; i < s.size(); i++)
        {
            if (ms[s[i]] != mt[t[i]])
            {
                return false;
            }
            ms[s[i]] = i + 1;
            mt[t[i]] = i + 1;
        }
        return true;
    };

    for (auto &t : p)
    {
        if (check(s, t))
        {
            cout << t << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
