#include <iostream>
#include <vector>
#include <algorithm>

struct Event
{
    int time, flg, idx;
};

int main()
{
    int N, M, X;
    std::cin >> N >> M >> X;

    std::vector<int> A(M), B(M), S(M), T(M);
    std::vector<Event> event;

    for (int i = 0; i < M; i++)
    {
        std::cin >> A[i] >> B[i] >> S[i] >> T[i];
        event.push_back({S[i], 1, i});
        event.push_back({T[i], 0, i});
    }

    // Sort events by time ( departure comes later )
    std::sort(event.begin(), event.end(), [](const Event &a, const Event &b)
              {
        if (a.time == b.time) {
            return a.flg < b.flg;
        }
        return a.time < b.time; });

    std::vector<int> ans(M);
    ans[0] = X;
    std::vector<int> station(N + 1);

    // Process events in order
    for (const auto &e : event)
    {
        int t = e.time, f = e.flg, i = e.idx;
        if (f == 1)
        { // Departure
            if (i != 0)
            { // Not X1, record difference between current arrival time and scheduled time
                ans[i] = std::max(0, station[A[i]] - t);
            }
        }
        else
        { // Arrival, record maximum of arrival time and arrival time + current delay
            station[B[i]] = std::max(station[B[i]], t + ans[i]);
        }
    }

    // Output answer
    for (int i = 1; i < M; i++)
    {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}