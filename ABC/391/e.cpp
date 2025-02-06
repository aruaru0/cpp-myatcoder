#include <iostream>
#include <string>
#include <tuple>

using namespace std;

// べき乗をループで計算する関数
int power(int base, int exp)
{
    int result = 1;
    for (int i = 0; i < exp; ++i)
    {
        result *= base;
    }
    return result;
}

tuple<char, int> f(const string &A, int l, int r)
{
    if (l + 1 == r)
    {
        return {A[l], 1};
    }
    int m1 = (2 * l + r) / 3;
    int m2 = (l + 2 * r) / 3;

    auto [val1, cnt1] = f(A, l, m1);
    auto [val2, cnt2] = f(A, m1, m2);
    auto [val3, cnt3] = f(A, m2, r);

    if (val1 == val2 && val2 == val3)
    {
        return {val1, cnt1 + cnt2 + cnt3 - max(max(cnt1, cnt2), cnt3)};
    }
    else if (val1 == val2)
    {
        return {val1, min(cnt1, cnt2)};
    }
    else if (val1 == val3)
    {
        return {val1, min(cnt1, cnt3)};
    }
    else if (val2 == val3)
    {
        return {val2, min(cnt2, cnt3)};
    }

    // これは理論上起こることはないが、コンパイラを通すためのダミー返り値
    return {' ', 0};
}

int main()
{
    int N;
    string A;

    cin >> N >> A;

    auto [_, result] = f(A, 0, power(3, N));
    cout << result << endl;

    return 0;
}
