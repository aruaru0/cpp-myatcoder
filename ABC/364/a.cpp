#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "sweet")
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        if (i != n - 1 && cnt == 2)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}