#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S;
  cin >> S;
  int n = S.size();
  long long MOD = 998244353;

  // dp[i][j] ... i文字目まで見て最後がj（0,1,2)の場合の文字を含む部分列の個数
  vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      dp[i + 1][j] = dp[i][j];
    }
    int cur = S[i] - 'a';
    for (int j = 0; j < 3; j++) {
      if (j == cur) {
        dp[i + 1][cur]++;
      } else {
        dp[i + 1][cur] += dp[i][j];
      }
    }
    dp[i + 1][cur] %= MOD;
  }

  cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD << endl;

  return 0;
}
