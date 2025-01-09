#include <bits/stdc++.h>
using namespace std;
int swh(int x)
{
    int ans = 0;
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
bool hs(int a)
{
    if (a % swh(a) == 0)
    {
        return true;
    }
    return false;
}
void print0(int gs)
{
    for (int i = 1; i <= gs; i++)
    {
        cout << 0;
    }
}
int main()
{
    string s;
    cin >> s;
    if (s.size() <= 7)
    {
        int n = stoi(s);
        for (int i = n; i < 2 * n; i++)
        {
            if (hs(i) && hs(i + 1))
            {
                cout << i;
                return 0;
            }
        }
        cout << -1;
        return 0;
    }
    int p1 = s[0] - '0';
    int p2 = s[1] - '0';
    int p = p1 * 10 + p2;
    if (p >= 10 && p <= 16)
    {
        cout << 17;
    }
    else if (p >= 17 && p <= 25)
    {
        cout << 26;
    }
    else if (p >= 26 && p <= 34)
    {
        cout << 35;
    }
    else if (p >= 35 && p <= 43)
    {
        cout << 44;
    }
    else if (p >= 44 && p <= 52)
    {
        cout << 53;
    }
    else if (p >= 53 && p <= 61)
    {
        cout << 62;
    }
    else if (p >= 62 && p <= 70)
    {
        cout << 71;
    }
    else if (p >= 71 && p <= 79)
    {
        cout << 80;
    }
    else if (p >= 80 && p <= 99)
    {
        cout << 107;
    }
    print0(s.size() - 2);
    return 0;
}