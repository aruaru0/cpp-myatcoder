#include <iostream>  // 入出力操作 (cin, cout)
#include <vector>    // 動的配列 (std::vector)
#include <string>    // 文字列 (std::string)
#include <algorithm> // std::min, std::max, std::abs, std::lower_bound, std::upper_bound
#include <queue>     // 優先度キュー (std::priority_queue)
#include <cmath>     // 数学関数 (std::abs)
#include <map>       // 連想配列 (std::map, DSU::Groupsで利用)
#include <numeric>   // std::iota など、数値操作関連

// Goのプログラムをコンバート

// 高速I/O設定
// 標準C++ストリームとC標準ライブラリのI/Oストリームの同期を解除し、
// cinとcoutの結合をNULLに設定することで、入出力速度を向上させます。
void setup_io()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

// 標準入力から整数を読み取る関数
int getI()
{
    int x;
    std::cin >> x;
    return x;
}

// 標準入力から浮動小数点数を読み取る関数
double getF()
{
    double x;
    std::cin >> x;
    return x;
}

// 標準入力から文字列を読み取る関数 (単語単位)
std::string getS()
{
    std::string s;
    std::cin >> s;
    return s;
}

// N個の整数を読み取り、std::vector<int>として返す関数
std::vector<int> getInts(int N)
{
    std::vector<int> ret(N);
    for (int i = 0; i < N; ++i)
    {
        ret[i] = getI();
    }
    return ret;
}

// 可変引数テンプレートを使用した出力関数
// 最後の引数を出力し、改行します。
template <typename T>
void out(T x)
{
    std::cout << x << '\n';
}

// 複数の引数を出力し、スペースで区切ります。
template <typename T, typename... Args>
void out(T x, Args... args)
{
    std::cout << x << " ";
    out(args...);
}

// std::vectorの内容をスペース区切りで出力する関数
template <typename T>
void outSlice(const std::vector<T> &s)
{
    if (s.empty())
    {
        return;
    }
    for (size_t i = 0; i < s.size() - 1; ++i)
    {
        std::cout << s[i] << " ";
    }
    std::cout << s.back() << '\n';
}

// 複数の引数の中から最小値を見つけるテンプレート関数
// C++11以降のinitializer_listや可変引数テンプレートを利用
template <typename T>
T nmin(T first) { return first; } // 再帰の終端条件

template <typename T, typename... Args>
T nmin(T first, Args... args)
{
    return std::min(first, nmin(args...));
}

// 複数の引数の中から最大値を見つけるテンプレート関数
template <typename T>
T nmax(T first) { return first; } // 再帰の終端条件

template <typename T, typename... Args>
T nmax(T first, Args... args)
{
    return std::max(first, nmax(args...));
}

// ポインタを介して値を更新する最小値チェック関数
bool chmin(int *a, int b)
{
    if (*a < b)
    {
        return false;
    }
    *a = b;
    return true;
}

// ポインタを介して値を更新する最大値チェック関数
bool chmax(int *a, int b)
{
    if (*a > b)
    {
        return false;
    }
    *a = b;
    return true;
}

// 2つの整数の絶対差を計算する関数
int asub(int a, int b)
{
    return std::abs(a - b);
}

// ソートされたstd::vector内で、指定された値以上の最初の要素のインデックスを返す
// std::lower_boundはイテレータを返すため、- .begin()でインデックスに変換
int lowerBound(const std::vector<int> &a, int x)
{
    return std::lower_bound(a.begin(), a.end(), x) - a.begin();
}

// ソートされたstd::vector内で、指定された値より大きい最初の要素のインデックスを返す
// std::upper_boundはイテレータを返すため、- .begin()でインデックスに変換
int upperBound(const std::vector<int> &a, int x)
{
    return std::upper_bound(a.begin(), a.end(), x) - a.begin();
}

// 優先度キューに格納する要素の構造体
// a: 距離（優先度）、u: 点1のインデックス、v: 点2のインデックス
struct pqi
{
    int a, u, v;

    // std::priority_queueはデフォルトで最大ヒープなので、
    // 最小ヒープとして動作させるためにoperator>をオーバーロードします。
    // 'a'の値が小さいほど優先度が高くなるように定義します。
    bool operator>(const pqi &other) const
    {
        return a > other.a;
    }
};

// Disjoint Set Union (Union-Find Tree) クラス
class DSU
{
public:
    // parentOrSize[i]が負の場合、iは根であり、その絶対値は集合のサイズを表す。
    // 正の場合、iは親のインデックスを表す。
    std::vector<int> parentOrSize;
    int n; // DSUが管理する現在の要素数

    // コンストラクタ
    // initial_n: 初期要素数
    DSU(int initial_n) : n(initial_n)
    {
        parentOrSize.assign(n, -1); // 全ての要素を独立した集合として初期化
    }

    // DSUのサイズを1つ増やし、新しい要素を独立した集合として追加します。
    // Go版とは異なり、既存のDSUオブジェクトを直接変更します。
    void inc()
    {
        n++;
        parentOrSize.push_back(-1); // 新しい孤立した要素を追加
    }

    // 2つの要素を結合します。
    // 戻り値: 結合後の新しいリーダーのインデックス
    int Merge(int a, int b)
    {
        int x = Leader(a); // aのリーダー
        int y = Leader(b); // bのリーダー
        if (x == y)
        {
            return x; // すでに同じ集合の場合
        }
        // サイズの大きい方に小さい方をマージ (Union by Size)
        if (-parentOrSize[x] < -parentOrSize[y])
        {
            std::swap(x, y); // xを大きい集合のリーダーにする
        }
        parentOrSize[x] += parentOrSize[y]; // サイズを更新
        parentOrSize[y] = x;                // 小さい方のリーダーの親を大きい方に設定
        return x;
    }

    // 2つの要素が同じ集合に属するかどうかを判定します。
    bool Same(int a, int b)
    {
        return Leader(a) == Leader(b);
    }

    // 要素aのリーダー（根）を見つけます。
    // 経路圧縮 (Path Compression) を行います。
    int Leader(int a)
    {
        if (parentOrSize[a] < 0)
        {
            return a; // aが根の場合
        }
        // 経路圧縮: 親を直接根に繋ぎ直す
        return parentOrSize[a] = Leader(parentOrSize[a]);
    }

    // 要素aが属する集合のサイズを返します。
    int Size(int a)
    {
        return -parentOrSize[Leader(a)];
    }

    // (オプション) 各集合の要素リストを返します。
    // この関数はメインロジックでは使用されていませんが、完全性のために含めました。
    std::vector<std::vector<int>> Groups()
    {
        std::map<int, std::vector<int>> m;
        for (int i = 0; i < n; ++i)
        {
            m[Leader(i)].push_back(i);
        }
        std::vector<std::vector<int>> ret;
        for (auto const &pair : m)
        { // C++17 structured bindings
            ret.push_back(pair.second);
        }
        return ret;
    }
};

int main()
{
    setup_io(); // 高速I/Oを有効化

    int N, Q;
    N = getI(); // 初期点の数
    Q = getI(); // クエリの数

    std::vector<int> x(N), y(N); // 点のx, y座標
    for (int i = 0; i < N; ++i)
    {
        x[i] = getI();
        y[i] = getI();
    }

    // pqiを格納する最小ヒープ (std::greater<pqi>を使用)
    std::priority_queue<pqi, std::vector<pqi>, std::greater<pqi>> pq;

    // 全ての点のペア間のマンハッタン距離を計算し、優先度キューに格納
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i == j)
            {
                continue; // 同じ点同士はスキップ
            }
            int d = std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]);
            pq.push({d, i, j});
        }
    }

    DSU uf(N); // N個の要素を持つDSUを初期化

    // Q個のクエリを処理
    for (int qi = 0; qi < Q; ++qi)
    {
        int t = getI(); // クエリの種類

        if (t == 1)
        {
            // タイプ1クエリ: 新しい点を追加
            int a = getI();
            int b = getI();

            // 新しい点と既存の点全てとの距離を計算し、PQに追加
            // 新しい点のインデックスは現在のN（0からN-1まで既存の点）
            for (int i = 0; i < N; ++i)
            {
                int d = std::abs(a - x[i]) + std::abs(b - y[i]);
                pq.push({d, i, N});
            }
            x.push_back(a); // x座標のリストに新しい点を追加
            y.push_back(b); // y座標のリストに新しい点を追加
            uf.inc();       // DSUのサイズを増やし、新しい要素を追加
            N++;            // 全体の点数をインクリメント
        }
        else if (t == 2)
        {
            // タイプ2クエリ: 最小コストで集合を結合し、そのコストを出力
            // 全ての点がすでに1つの集合に属している場合 (連結グラフの場合)
            if (uf.Size(0) == N)
            {
                out(-1); // 結合できないため-1を出力
            }
            else
            {
                // PQの先頭から、すでに同じ集合に属する点のペアを削除
                while (!pq.empty() && uf.Same(pq.top().u, pq.top().v))
                {
                    pq.pop();
                }

                // ここでPQが空になることは、uf.Size(0) != N の条件から通常あり得ないが、
                // 防御的なプログラミングとしてチェック。
                if (pq.empty())
                {
                    out(-1);
                    continue;
                }

                int cur_cost = pq.top().a; // 現在の最小コスト
                // 同じ最小コストを持つ全ての辺を処理し、集合を結合
                while (!pq.empty() && pq.top().a == cur_cost)
                {
                    pqi edge = pq.top();
                    pq.pop();
                    uf.Merge(edge.u, edge.v); // 集合を結合
                }
                out(cur_cost); // 最小コストを出力
            }
        }
        else
        {
            // タイプ3クエリ: 2つの点が同じ集合に属するか判定
            int u = getI() - 1; // 0-indexedに変換
            int v = getI() - 1; // 0-indexedに変換
            if (uf.Same(u, v))
            {
                out("Yes");
            }
            else
            {
                out("No");
            }
        }
    }

    return 0; // プログラム成功終了
}