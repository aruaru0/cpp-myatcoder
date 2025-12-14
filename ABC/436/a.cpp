#include <iostream>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    string t;
    for (int i = 0; i < n - s.size(); i++)
    {
        t += 'o';
    }

    cout << t + s << endl;
    return 0;
}