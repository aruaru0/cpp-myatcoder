#include <iostream>

using namespace std;

int main()
{
    string s = "HelloWorld";
    int x;
    cin >> x;

    cout << s.substr(0, x - 1) << s.substr(x, s.size()) << endl;
}