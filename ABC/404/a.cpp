#include <iostream>
#include <set>

using namespace std;

int main()
{
    string s;
    cin >> s;
    set<char> st;
    for (char c : s)
    {
        st.insert(c);
    }
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (st.find(i) == st.end())
        {
            cout << (char)i << endl;
            return 0;
        }
    }
}