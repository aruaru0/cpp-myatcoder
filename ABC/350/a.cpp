#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int e = stoi(s.substr(3, s.size()));

    if (e > 0 && e < 350 && e != 316)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}