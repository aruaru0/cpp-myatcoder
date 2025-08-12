#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <set>
#include <map>
using std::array;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::set;
using std::vector;

#include <atcoder/all>
using mint = atcoder::modint998244353;
using atcoder::segtree;

typedef long long int ll;

vector<mint> frac, invf;
void f_init(ll n)
{
    frac.resize(n + 1);
    invf.resize(n + 1);
    frac[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        frac[i] = frac[i - 1] * i;
    }
    invf[n] = frac[n].inv();
    for (ll i = n; i >= 1; i--)
    {
        invf[i - 1] = invf[i] * i;
    }
}
mint ncr(ll n, ll r)
{
    if (n < r || n < 0 || r < 0)
        return 0;

    if (frac.size() <= n)
    {
        f_init(n + 5);
    }
    return frac[n] * invf[n - r] * invf[r];
}

ll n, q;

using Mat = array<array<mint, 2>, 2>;
const Mat unity = {
    (array<mint, 2>){1, 0},
    (array<mint, 2>){0, 1}};
Mat operator*(const Mat &l, const Mat &r)
{
    Mat x = {
        (array<mint, 2>){0, 0},
        (array<mint, 2>){0, 0}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                x[i][j] += l[i][k] * r[k][j];
            }
        }
    }
    return x;
}

Mat seg_op(Mat l, Mat r)
{
    return l * r;
}
Mat seg_e(void)
{
    return unity;
}

// n boxes, r balls into unique boxes, no adjacent boxes
mint noadj(ll n, ll r)
{
    if (n < r || r < 0)
        return 0;
    return ncr((n + 1) - r, r);
}

Mat lenmat(ll n, ll r)
{
    Mat x;
    x[0][0] = noadj(n - 1, r);
    if (n == 1)
    {
        x[0][1] = noadj(0, r - 1);
    }
    else
    {
        x[0][1] = noadj(n - 2, r - 1);
    }
    if (n == 1)
    {
        x[1][0] = noadj(0, r);
    }
    else
    {
        x[1][0] = noadj(n - 2, r);
    }
    if (n == 1)
    {
        x[1][1] = 0;
    }
    else if (n == 2)
    {
        x[1][1] = noadj(0, r - 1);
    }
    else
    {
        x[1][1] = noadj(n - 3, r - 1);
    }

    return x;
}

map<ll, ll> stidx; // set of i such that a_i != -1
void solve()
{
    segtree<Mat, seg_op, seg_e> seg(n);

    vector<mint> fib(n + 1);
    fib[0] = 1;
    fib[1] = 2;
    for (ll i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 2] + fib[i - 1];
    }

    stidx.insert({-1, 0}); // bottom
    stidx.insert({n, n});  // top
    for (ll qi = 0; qi < q; qi++)
    {
        ll x, y;
        cin >> x >> y;
        --x;

        // erase
        {
            auto it = stidx.find(x);
            if (it != stidx.end())
            {
                --it;
                ll ilow = (*it).first, vlow = (*it).second;
                ++it;
                ++it;
                ll ihigh = (*it).first, vhigh = (*it).second;
                --it;

                stidx.erase(it);
                seg.set(x, unity);
                if (ihigh < n)
                    seg.set(ihigh, lenmat(ihigh - ilow, vhigh - vlow));
            }
        }

        // add
        if (y != -1)
        {
            stidx.insert({x, y});
            auto it = stidx.find(x);
            --it;
            ll ilow = (*it).first, vlow = (*it).second;
            ++it;
            ++it;
            ll ihigh = (*it).first, vhigh = (*it).second;
            --it;

            seg.set(x, lenmat(x - ilow, y - vlow));
            if (ihigh < n)
                seg.set(ihigh, lenmat(ihigh - x, vhigh - y));
        }

        // answer
        Mat whole = seg.all_prod();
        ll remain;
        {
            auto it = stidx.find(n);
            --it;
            ll idx = (*it).first;

            remain = (n - 1) - idx;
        }
        mint ans = 0;
        ans += whole[0][0] * fib[remain];
        ans += whole[0][1] * fib[max(remain - 1, 0LL)];

        cout << ans.val() << "\n";
    }

    return;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    solve();

    return 0;
}
