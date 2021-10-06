// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/6075858a4c0848a296805955dff5eb04
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int testCase;
  cin >> testCase;
  while (testCase--) {
    int N;
    cin >> N;
    vector<vector<int>> arr(N, vector<int>(2)), dp(N, vector<int>(2));
    for (int j = 0; j < 2; j++)
      for (int i = 0; i < N; i++)
        cin >> arr[i][j];
    
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 2; j++) {
        int v = 0;
        if (1 < i) v = max(dp[i - 2][0], dp[i - 2][1]);
        if (i) v = max(v, dp[i - 1][1 - j]);
        dp[i][j] = v + arr[i][j];
      }
    }
    cout << max(dp[N - 1][0], dp[N - 1][1]) << '\n';
  }
}