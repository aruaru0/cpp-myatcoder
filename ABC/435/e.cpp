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
    ll N;
    int Q;
    cin >> N >> Q;

    set<pair<ll, ll>> segments;
    ll black_count = 0;

    for (int i = 0; i < Q; ++i)
    {
        ll L, R;
        cin >> L >> R;
        ll newL = L;
        ll newR = R;
        auto it = segments.lower_bound({L, -1});

        if (it != segments.begin())
        {
            it--;
            if (it->second < L - 1)
            {
                it++;
            }
        }

        while (it != segments.end())
        {
            ll curL = it->first;
            ll curR = it->second;

            if (curL > newR + 1)
            {
                break;
            }

            newL = min(newL, curL);
            newR = max(newR, curR);

            black_count -= (curR - curL + 1);

            it = segments.erase(it);
        }

        segments.insert({newL, newR});
        black_count += (newR - newL + 1);

        cout << N - black_count << "\n";
    }

    return 0;
}