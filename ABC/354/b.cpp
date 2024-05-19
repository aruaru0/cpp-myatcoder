#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> p(n);
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        int c;
        cin >> s >> c;
        p[i] = s;
        tot += c;
    }

    sort(p.begin(), p.end());

    cout << p[tot % n] << endl;
}
