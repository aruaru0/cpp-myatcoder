#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;

    cin >> s;

    string t;

    auto pos = s.find("HAGIYA");
    auto len = string("HAGIYA").length();

    s.replace(pos, len, "HAGIXILE");

    cout << s << endl;
}