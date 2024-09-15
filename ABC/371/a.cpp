#include <iostream>

using namespace std;

int main()
{
    char ab, ac, bc;
    cin >> ab >> ac >> bc;

    if (ab == '<' && ac == '<' && bc == '<')
    {
        cout << "B" << endl;
    }
    else if (ab == '>' && ac == '>' && bc == '>')
    {
        cout << "B" << endl;
    }
    else if (ab == '<' && ac == '<' && bc == '>')
    {
        cout << "C" << endl;
    }
    else if (ab == '>' && ac == '>' && bc == '<')
    {
        cout << "C" << endl;
    }
    else
    {
        cout << "A" << endl;
    }
}