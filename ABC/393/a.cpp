#include <iostream>

using namespace std;

int main()
{
    string s1, s2;

    cin >> s1 >> s2;

    // 1 .. sick sick
    // 2 .. sick fine
    // 3 .. fine sick
    // 4 .. fine fine
    if (s1 == "sick" && s2 == "sick")
    {
        cout << 1 << endl;
    }
    else if (s1 == "sick" && s2 == "fine")
    {
        cout << 2 << endl;
    }
    else if (s1 == "fine" && s2 == "sick")
    {
        cout << 3 << endl;
    }
    else
    {
        cout << 4 << endl;
    }
}