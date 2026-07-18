#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        string s;
        cin >> a >> b >> s;
        if (s == "keep")
        {
            tot += b - a;
        }
    }
    cout << tot << endl;
}