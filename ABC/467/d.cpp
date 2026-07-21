#include <iostream>
#include <numeric>
#include <tuple>
using namespace std;

tuple<long long, long long, long long> get_canonical(long long px, long long py,
                                                     long long qx,
                                                     long long qy)
{
    long long a = 2 * (qx - px);
    long long b = 2 * (qy - py);
    long long c = px * px + py * py - qx * qx - qy * qy;
    long long g = gcd(a, gcd(b, c));
    a /= g, b /= g, c /= g;
    if (a < 0)
        a = -a, b = -b, c = -c;
    if (a == 0 and b < 0)
        b = -b, c = -c;
    return {a, b, c};
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long px, py, qx, qy, rx, ry, sx, sy;
        cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
        auto [a1, b1, c1] = get_canonical(px, py, qx, qy);
        auto [a2, b2, c2] = get_canonical(rx, ry, sx, sy);
        if (a1 * b2 - a2 * b1 == 0)
        {
            if (a1 == a2 and b1 == b2 and c1 == c2)
            {
                cout << "Yes" << "\n";
            }
            else
            {
                cout << "No" << "\n";
            }
        }
        else
        {
            cout << "Yes" << "\n";
        }
    }
}
