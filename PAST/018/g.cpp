#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
template <class T>
void er(T a)
{
    cout << a << '\n';
    exit(0);
}
template <class T, class U>
inline bool chmax(T &a, const U &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T, class U>
inline bool chmin(T &a, const U &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    if (a == b)
        er("Yes");
    int x = n, y = -1;
    rep(i, n)
    {
        if (a[i] != b[i])
        {
            chmin(x, i);
            chmax(y, i);
        }
    }
    if (x == n - 1 or y == 0)
        er("No");
    if (x == y)
        er("No");
    else if (x + 1 == y)
    {
        if (a[x] != b[y] or a[y] != b[x])
            er("No");
        rep(i, n - 1) if (a[i] == a[i + 1]) er("Yes");
        rep(i, n - 1) if (b[i] == b[i + 1]) er("Yes");
        cout << "No\n";
    }
    else if (x + 2 == y)
    {
        vector<int> c = a;
        swap(a[x], a[x + 1]);
        swap(a[y - 1], a[y]);
        swap(c[y - 1], c[y]);
        swap(c[x], c[x + 1]);
        cout << ((a == b or c == b) ? "Yes" : "No") << '\n';
    }
    else
    {
        swap(a[x], a[x + 1]);
        swap(a[y - 1], a[y]);
        cout << (a == b ? "Yes" : "No") << '\n';
    }
}
