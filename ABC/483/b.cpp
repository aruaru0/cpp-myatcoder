#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> k(q);
    for (int i = 0; i < q; i++)
        cin >> k[i];

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        p[i] = i + 1;

    for (int qi = 0; qi < q; qi++)
    {
        int num = k[qi];
        for (int i = 0; i < num; i++)
        {
            p[i] = -p[i];
        }
        for (int i = 0; i < num / 2; i++)
        {
            swap(p[i], p[num - 1 - i]);
        }
    }

    for (int i = 0; i < n; i++)
        cout << p[i] << endl;

    return 0;
}