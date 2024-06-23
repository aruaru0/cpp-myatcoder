#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<P> s(n), t(n);
    rep(i, n) cin >> s[i].first >> s[i].second;
    rep(i, n) cin >> t[i].first >> t[i].second;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    // 一致するかどうか確認
    {
        bool ok = true;
        rep(i, n)
        {
            if (s[i].first != t[i].first || s[i].second != t[i].second)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    // sをx方向に反転
    vector<P> p(n);
    rep(i, n)
    {
        p[i].first = -s[i].first;
        p[i].second = s[i].second;
    }
    sort(p.begin(), p.end());
    {
        bool ok = true;
        int diff = p[0].first - t[0].first;
        rep(i, n)
        {
            if (p[i].second != t[i].second)
            {
                ok = false;
                break;
            }
            else if (diff != p[i].first - t[i].first)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    // sをx方向に反転
    rep(i, n)
    {
        p[i].first = s[i].first;
        p[i].second = -s[i].second;
    }
    sort(p.begin(), p.end());
    {
        bool ok = true;
        int diff = p[0].second - t[0].second;
        rep(i, n)
        {
            if (p[i].first != t[i].first)
            {
                ok = false;
                break;
            }
            else if (diff != p[i].second - t[i].second)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}