#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using mint = modint998244353;

// Aho-Corasick
// https://youtu.be/BYoRvdgI5EU?t=9633
struct Aho
{
    using MP = unordered_map<char, int>;
    vector<MP> to;
    vector<int> cnt, fail;
    Aho() : to(1), cnt(1) {}
    int add(const string &s)
    {
        int v = 0;
        for (char c : s)
        {
            if (!to[v].count(c))
            {
                to[v][c] = to.size();
                to.push_back(MP());
                cnt.push_back(0);
            }
            v = to[v][c];
        }
        cnt[v]++;
        return v;
    }
    void init()
    {
        fail = vector<int>(to.size(), -1);
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto [c, u] : to[v])
            {
                fail[u] = (*this)(fail[v], c);
                cnt[u] += cnt[fail[u]];
                q.push(u);
            }
        }
    }
    int operator()(int v, char c) const
    {
        while (v != -1)
        {
            auto it = to[v].find(c);
            if (it != to[v].end())
                return it->second;
            v = fail[v];
        }
        return 0;
    }
    int operator[](int v) const { return cnt[v]; }
};

// https://youtu.be/ylWYSurx10A?t=2352
template <typename T>
struct Matrix
{
    int h, w;
    vector<vector<T>> d;
    Matrix() {}
    Matrix(int h, int w, T val = 0) : h(h), w(w), d(h, vector<T>(w, val)) {}
    Matrix &unit()
    {
        assert(h == w);
        rep(i, h) d[i][i] = 1;
        return *this;
    }
    const vector<T> &operator[](int i) const { return d[i]; }
    vector<T> &operator[](int i) { return d[i]; }
    Matrix operator*(const Matrix &a) const
    {
        assert(w == a.h);
        Matrix r(h, a.w);
        rep(i, h) rep(k, w) rep(j, a.w)
        {
            r[i][j] += d[i][k] * a[k][j];
        }
        return r;
    }
    Matrix pow(long long t) const
    {
        assert(h == w);
        if (!t)
            return Matrix(h, h).unit();
        if (t == 1)
            return *this;
        Matrix r = pow(t >> 1);
        r = r * r;
        if (t & 1)
            r = r * (*this);
        return r;
    }
    // https://youtu.be/-j02o6__jgs?t=11273
    /* mint only
    mint det() {
      assert(h == w);
      mint res = 1;
      rep(k,h) {
        for (int i = k; i < h; ++i) {
          if (d[i][k] == 0) continue;
          if (i != k) {
            swap(d[i],d[k]);
            res = -res;
          }
        }
        if (d[k][k] == 0) return 0;
        res *= d[k][k];
        mint inv = mint(1)/d[k][k];
        rep(j,h) d[k][j] *= inv;
        for (int i = k+1; i < h; ++i) {
          mint c = d[i][k];
          for (int j = k; j < h; ++j) d[i][j] -= d[k][j]*c;
        }
      }
      return res;
    }
    //*/
};

int main()
{
    int n, k;
    cin >> n >> k;
    Aho aho;
    rep(i, k)
    {
        string s;
        cin >> s;
        aho.add(s);
    }
    aho.init();
    int m = aho.to.size();

    Matrix<mint> a(m, m);
    rep(i, m)
    {
        rep(c, 26)
        {
            int j = aho(i, 'a' + c);
            if (aho[j] == 0)
                a[i][j] += 1;
        }
    }

    Matrix<mint> x(1, m);
    x[0][0] = 1;
    x = x * a.pow(n);
    mint ans;
    rep(i, m) ans += x[0][i];
    cout << ans.val() << endl;
    return 0;
}