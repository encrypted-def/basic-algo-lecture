// Authored by : sukam09
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/a0c4059281d8484789b8431dc7be6f8e
#include <bits/stdc++.h>
using namespace std;

int n;
int board[21][21];
int dp[21][21][3];  // i는 행, j는 열, k는 0, 1, 2일 때 각각 가로, 세로, 대각선 아래 방향을 나타냄
int ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> board[i][j];

  // 맨 윗줄에서 벽을 만날때까지 가로 방향의 파이프를 우측으로 이동시킬 수 있음
  for (int i = 1; i < n; i++) {
    if (board[0][i]) break;
    dp[0][i][0] = 1;
  }
  
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      // 해당 칸에 벽이 있으면 어떤 파이프도 올 수 없음
      if (board[i][j]) continue;
      dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
      dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
      // 해당 칸 위쪽이나 왼쪽에 벽이 있으면 대각선 아래 방향의 파이프가 올 수 없음
      if (board[i - 1][j] || board[i][j - 1]) continue;
      for (int k = 0; k < 3; k++)
        dp[i][j][2] += dp[i - 1][j - 1][k];
    }
  }

  for (int i = 0; i < 3; i++)
    ans += dp[n - 1][n - 1][i];
  cout << ans;
}
/*
DP를 이용한 풀이
*/
