#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if ((A == B && B == C) || A + B == C || B + C == A || C + A == B)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}