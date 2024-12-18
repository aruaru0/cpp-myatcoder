#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int Q;
    cin >> Q;

    queue<ll> q;

    ll current_time = 0;
    rep(qi, Q)
    {
        int Command;
        cin >> Command;
        if (Command == 1)
        {
            q.push(current_time);
        }
        else if (Command == 2)
        {
            int t;
            cin >> t;
            current_time += t;
        }
        else
        {
            int h;
            cin >> h;
            int cnt = 0;
            while (q.size() != 0 && current_time - q.front() >= h)
            {
                q.pop();
                cnt++;
            }

            cout << cnt << endl;
        }
    }
    return 0;
}
