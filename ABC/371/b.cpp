#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<bool> x(n);

    for (int i = 0; i < m; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        a--;
        if (b == 'M')
        {
            if (x[a] == false)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            x[a] = true;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}