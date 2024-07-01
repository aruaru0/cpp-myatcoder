#include <iostream>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s, t;
    cin >> s >> t;

    for (int w = 1; w < s.size(); w++)
    {
        for (int c = 0; c < w; c++)
        {
            string x = "";
            for (int i = c; i < s.size(); i += w)
            {
                x += s[i];
            }
            if (x == t)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}