#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Q;
    cin >> Q;

    vector<int> a(100, 0);
    for (int qi = 0; qi < Q; qi++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        else
        {
            cout << a[a.size() - 1] << endl;
            a.pop_back();
        }
    }
}