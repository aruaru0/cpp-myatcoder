#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;
    vector<int> d(n - 1);
    rep(i, n - 1)
    {
        cin >> d[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int tot = 0;
        for (int j = i; j < n - 1; j++)
        {
            tot += d[j];
            cout << tot << " ";
        }
        cout << endl;
    }
}