#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> w(n);

    rep(i, n)
    {
        cin >> a[i];
        a[i]--;
    }

    rep(i, n)
    {
        cin >> w[i];
    }
    int total = accumulate(w.begin(), w.end(), 0);

    vector<int> p(n);
    rep(i, n)
    {
        p[a[i]] = max(p[a[i]], w[i]);
    }
    int rest = accumulate(p.begin(), p.end(), 0);

    cout << total - rest << endl;
}