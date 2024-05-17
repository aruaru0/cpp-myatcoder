#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> p(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> p[i];
    }

    long long tot = 0;
    for (auto e : a)
    {
        tot += p[e - 1];
    }

    cout << tot << endl;
}