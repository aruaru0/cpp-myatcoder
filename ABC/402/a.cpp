#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    for (auto e : s)
    {
        // 大文字かどうかチェック
        if (isupper(e))
        {
            cout << e;
        }
    }
    cout << endl;
}