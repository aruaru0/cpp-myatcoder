#include <iostream>

using namespace std;

int main()
{
    // 入力を読み込む
    int A1, A2, A3;
    cin >> A1 >> A2 >> A3;

    // 条件を満たすかどうかチェック
    if (A1 * A2 == A3 || A1 * A3 == A2 || A2 * A3 == A1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}