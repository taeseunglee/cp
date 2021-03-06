#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[N], t[N];
int dp[N][N][15][2];

int main() {
  int n, m, lim;
  scanf("%d %d %d %s %s", &n, &m, &lim, s, t);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < 15; k++) {
        dp[i][j][k][0] = dp[i][j][k][1] = -1e9;
      }
    }
  }
  dp[0][0][0][0] = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      for(int k = 0; k <= lim; k++) {
        int zero = dp[i][j][k][0];
        int one = dp[i][j][k][1];
        if(s[i] == t[j]) {
          dp[i + 1][j + 1][k + 1][1] = max(dp[i + 1][j + 1][k + 1][1], zero + 1);
          dp[i + 1][j + 1][k + 1][1] = max(dp[i + 1][j + 1][k + 1][1], one + 1);
          dp[i + 1][j + 1][k][1] = max(dp[i + 1][j + 1][k][1], one + 1);
        }
        for(int a = 0; a < 2; a++) {
          dp[i + 1][j][k][0] = max(dp[i + 1][j][k][0], dp[i][j][k][a]);
          dp[i][j + 1][k][0] = max(dp[i][j + 1][k][0], dp[i][j][k][a]);
        }
      }
    }
  }
  int ans = 0;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= m; j++) {
      ans = max(ans, dp[i][j][lim][0]);
      ans = max(ans, dp[i][j][lim][1]);
    }
  }
  cout << ans << endl;
  return 0;
}
