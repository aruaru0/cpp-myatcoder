#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int Q;
    cin >> Q;

    deque<int> a;

    for (int qi = 0; qi < Q; qi++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        else if (type == 2)
        {
            if (!a.empty())
                cout << a.front() << endl;
            a.pop_front();
        }
    }
}