#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n * 2);
    rep(i, n * 2) cin >> a[i];

    int cnt = 0;
    for (int i = 2; i < n * 2; i++)
    {
        if (a[i - 2] == a[i])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}