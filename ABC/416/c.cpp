#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, x;
    cin >> n >> k >> x;

    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<string> m;

    auto f = [&](auto f, int cnt, string t = "")
    {
        if (cnt == k)
        {
            m.push_back(t);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            f(f, cnt + 1, t + s[i]);
        }
    };

    f(f, 0);
    sort(m.begin(), m.end());
    cout << m[x - 1] << endl;
    return 0;
}