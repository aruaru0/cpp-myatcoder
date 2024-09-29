#include <iostream>

using namespace std;

int main()
{
    int cnt = 0;
    for (int i = 1; i <= 12; i++)
    {
        string s;
        cin >> s;
        if (s.size() == i)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}