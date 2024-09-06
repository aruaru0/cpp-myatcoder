#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int cur_l = -1, cur_r = -1;
    int tot_l = 0, tot_r = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        char s;
        cin >> a >> s;
        if (s == 'L')
        {
            if (cur_l == -1)
            {
                cur_l = a;
            }
            tot_l += abs(a - cur_l);
            cur_l = a;
        }
        else
        {
            if (cur_r == -1)
            {
                cur_r = a;
            }
            tot_r += abs(a - cur_r);
            cur_r = a;
        }
    }

    cout << tot_l + tot_r << endl;
}