#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int a = 0, b = 0, c = 0;
    for (auto e : s)
    {
        switch (e)
        {
        case 'A':
            a++;
            break;
        case 'B':
            if (a > b)
                b++;
            break;
        case 'C':
            if (b > c)
                c++;
            break;
        }
    }

    cout << c << endl;
}