#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m;
    cin >> m;

    vector<int> a;
    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j < m % 3; j++)
        {
            a.push_back(i);
        }
        m /= 3;
    }

    cout << a.size() << endl;
    for (auto e : a)
        cout << e << " ";
    cout << endl;
}