#include <iostream>
#include <deque>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int Q;
    cin >> Q;

    deque<P> p;

    rep(qi, Q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int c, x;
            cin >> c >> x;
            p.push_back(P(x, c));
        }
        else
        {
            int k;
            cin >> k;
            ll sum = 0;
            while (k != 0)
            {
                if (k >= p[0].second)
                {
                    sum += (ll)p[0].first * p[0].second;
                    k -= p[0].second;
                    p.pop_front();
                }
                else
                {
                    sum += (ll)p[0].first * k;
                    p[0].second -= k;
                    k = 0;
                }
            }

            cout << sum << endl;
        }
    }
}