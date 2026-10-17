#include <iostream>

using namespace std;

int main()
{
    string s0, s1;
    cin >> s0 >> s1;

    for (int i = 0; i < 2; i++)
    {
        int j = 1 - i;
        if (s0[i] == 'A' && s1[j] == 'D')
        {
            cout << "No" << endl;
            return 0;
        }
        if (s0[i] == 'D' && s1[j] == 'A')
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}