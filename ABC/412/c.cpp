#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A)
        cin >> a;

    vector<int> used(N);
    int ans = 1, last = 0;
    while (true)
    {
        if (A[last] * 2 >= A[N - 1])
        {
            ans += 1;
            break;
        }
        int nxt = -1;
        for (int i = 1; i <= N - 1; i++)
        {
            if (used[i])
                continue;
            if (A[last] * 2 >= A[i])
            {
                if (nxt != -1 && A[nxt] >= A[i])
                    continue;
                nxt = i;
            }
        }
        if (nxt == -1 || A[nxt] <= A[last])
        {
            cout << -1 << endl;
            return;
        }
        ans++, last = nxt, used[nxt] = 1;
    }
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
}
