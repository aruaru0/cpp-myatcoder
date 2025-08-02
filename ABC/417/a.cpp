#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;
    string t("");

    for (int i = a; i < n - b; i++)
    {
        t += s[i];
    }

    cout << t << endl;
}