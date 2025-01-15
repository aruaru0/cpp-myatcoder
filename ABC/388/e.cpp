#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int i = 0;
    int j = n / 2;
    int cnt = 0;
    while (i < n / 2 && j < n)
    {
        if (a[i] * 2 <= a[j])
        {
            cnt++;
            i++, j++;
        }
        else
        {
            j++;
        }
    }

    cout << cnt << endl;
}