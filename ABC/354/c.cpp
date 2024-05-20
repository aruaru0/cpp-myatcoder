#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using P = tuple<int, int, int>;

int main()
{
    int n;
    cin >> n;
    vector<P> card(n);
    for (int i = 0; i < n; i++)
    {
        int a, c;
        cin >> a >> c;
        card[i] = make_tuple(a, c, i + 1);
    }

    sort(card.begin(), card.end(), [](P a, P b)
         { return get<0>(a) > get<0>(b); });

    vector<int> ans;
    int min_cost = 1100000000;
    for (auto e : card)
    {
        int a = get<0>(e);
        int c = get<1>(e);
        int idx = get<2>(e);
        if (c < min_cost)
        {
            min_cost = c;
            ans.push_back(idx);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto e : ans)
    {
        cout << e << " ";
    }
    cout << endl;
}