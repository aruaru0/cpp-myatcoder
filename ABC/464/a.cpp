#include <iostream>

using namespace std;

int main()
{
    string s;

    cin >> s;

    int ne = 0, ns = 0;
    for (auto e : s)
    {
        if (e == 'E')
        {
            ne++;
        }
        else
        {
            ns++;
        }
    }

    if (ne > ns)
    {
        cout << "East" << endl;
    }
    else
    {
        cout << "West" << endl;
    }
}