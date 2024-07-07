#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++)
        cout << a[i] << " ";
    cout << x << " ";
    for (int i = k; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}