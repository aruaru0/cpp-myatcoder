#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i] != '/')
            continue;
        // 中央が'/'の場合、左右に探索を行う
        int d = 0;
        while (true)
        {
            int j = i - (d + 1);
            int k = i + (d + 1);
            if (!(0 <= j and j < N))
                break;
            if (!(0 <= k and k < N))
                break;
            if (S[j] != '1')
                break;
            if (S[k] != '2')
                break;
            d++;
        }
        ans = max(ans, 1 + d * 2);
    }
    cout << ans << "\n";
}
