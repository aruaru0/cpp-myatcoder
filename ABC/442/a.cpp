#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int cnt = 0;
    for (auto e : s)
    {
        if (e == 'i' || e == 'j')
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}