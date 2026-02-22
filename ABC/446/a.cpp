#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    s[0] = tolower(s[0]);
    cout << "Of" << s[0] << endl;
}