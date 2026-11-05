#include <iostream>
#include <vector>
#include <cstdint>

// 素因数分解し、vector を作成
std::vector<long long> Pfs(long long n)
{
    std::vector<long long> pfs;
    while (n % 2 == 0)
    {
        pfs.push_back(2);
        n /= 2;
    }
    for (long long i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            pfs.push_back(i);
            n /= i;
        }
    }
    if (n > 2)
    {
        pfs.push_back(n);
    }
    return pfs;
}

int main()
{
    // 高速入出力設定
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N;
    int M;
    if (!(std::cin >> N >> M))
        return 0;

    // N の素因数リストを取得し、mod M を取っておく
    std::vector<long long> rawP = Pfs(N);
    int L = static_cast<int>(rawP.size());
    std::vector<int> P(L);
    for (int i = 0; i < L; ++i)
    {
        P[i] = static_cast<int>(rawP[i] % M);
    }

    std::vector<int> ans(M, -1);

    // 状態数: (L + 1) * M
    int totalStates = (L + 1) * M;
    std::vector<uint64_t> visited((totalStates + 63) / 64, 0);

    auto isVisited = [&](int s, int u) -> bool
    {
        int idx = s * M + u;
        return (visited[idx >> 6] & (1ULL << (idx & 63))) != 0;
    };

    auto setVisited = [&](int s, int u)
    {
        int idx = s * M + u;
        visited[idx >> 6] |= (1ULL << (idx & 63));
    };

    // 初期状態: t = 1, x = 1 (mod M)
    int startU = 1 % M;
    setVisited(0, startU);
    ans[startU] = 1;
    int remaining = M - 1;
    if (M == 1)
    {
        remaining = 0;
    }

    std::vector<int> qCur, qNext, qNextRound;
    qCur.reserve(M);
    qNext.reserve(M);
    qNextRound.reserve(M);

    qCur.push_back(startU);
    int t = 1;

    while (!qCur.empty() && remaining > 0)
    {
        for (int s = 0; s < L; ++s)
        {
            int p = P[s];
            qNext.clear();

            for (int u : qCur)
            {
                int nu = static_cast<int>((1LL * u * p) % M);
                if (!isVisited(s + 1, nu))
                {
                    setVisited(s + 1, nu);
                    if (ans[nu] == -1)
                    {
                        ans[nu] = t;
                        remaining--;
                    }
                    qNext.push_back(nu);
                }

                if (!isVisited(s + 1, u))
                {
                    setVisited(s + 1, u);
                    if (ans[u] == -1)
                    {
                        ans[u] = t;
                        remaining--;
                    }
                    qNext.push_back(u);
                }
            }
            qCur.swap(qNext);
        }

        t++;
        qNextRound.clear();
        for (int u : qCur)
        {
            if (!isVisited(0, u))
            {
                setVisited(0, u);
                qNextRound.push_back(u);
            }
        }
        qCur = qNextRound;
    }

    for (int k = 0; k < M; ++k)
    {
        std::cout << ans[k] << "\n";
    }

    return 0;
}