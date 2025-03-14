// Authored by : hgmhc
// Co-authored by : -
// http://boj.kr/89025e1f01224efd8a5ddb2f5dd01ca4
#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
long long dp[N][10];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = 1;
    for (int j = 1; j < 10; ++j)
      dp[i][j] = (dp[i][j-1]+dp[i-1][j])%10007;
  }
  cout << accumulate(dp[n],dp[n]+10,0)%10007;
}
