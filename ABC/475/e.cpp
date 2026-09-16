#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    int to[2];
    int cnt;
    Node() : cnt(0)
    {
        to[0] = -1;
        to[1] = -1;
    }
};

vector<Node> trie;

void insert(const vector<int> &s, int delta)
{
    int curr = 0;
    trie[curr].cnt += delta;
    for (int b : s)
    {
        if (trie[curr].to[b] == -1)
        {
            trie[curr].to[b] = trie.size();
            trie.emplace_back();
        }
        curr = trie[curr].to[b];
        trie[curr].cnt += delta;
    }
}

bool check(const vector<int> &s, int M)
{
    int curr = 0;
    int rem_M = M;
    for (int b : s)
    {
        int c0 = 0;
        int next0 = trie[curr].to[0];
        if (next0 != -1)
        {
            c0 = trie[next0].cnt;
        }

        if (b == 0)
        {
            if (c0 <= rem_M)
            {
                return true;
            }
            else
            {
                curr = next0;
            }
        }
        else
        {
            if (c0 <= rem_M)
            {
                rem_M -= c0;
                curr = trie[curr].to[1];
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    if (!(cin >> N >> M >> K))
        return 0;

    string T;
    cin >> T;

    vector<vector<int>> A(N, vector<int>(K));
    trie.reserve(16000000);
    trie.emplace_back();

    for (int i = 0; i < N; ++i)
    {
        string S;
        cin >> S;
        for (int j = 0; j < K; ++j)
        {
            A[i][j] = (S[j] == T[j] ? 0 : 1);
        }
        insert(A[i], 1);
    }

    int Q;
    cin >> Q;
    while (Q--)
    {
        int i, j;
        cin >> i >> j;
        --i;
        --j;

        insert(A[i], -1);
        A[i][j] ^= 1;
        insert(A[i], 1);

        if (check(A[i], M))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}