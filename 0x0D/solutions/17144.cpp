// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/7d2a9e03cd80416a8a7764b5dfdb8609
#include <bits/stdc++.h>
using namespace std;

int board1[50][50];
int board2[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int r, c, t;
int x1, x2;
bool OOB(int a, int b) { return a < 0 || a >= r || b < 0 || b >= c; }

void diffuse() {
  int board2[50][50];
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) board2[i][j] = board1[i][j];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (board1[i][j] <= 0) continue;
      int tmp = board1[i][j] / 5;
      for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (0 <= nx && nx < r && 0 <= ny && ny < c && board1[nx][ny] != -1) {
          board2[nx][ny] += tmp;
          board2[i][j] -= tmp;
        }
      }
    }
  }
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) board1[i][j] = board2[i][j];
}

void purify() {
  for (int i = x1 - 1; i > 0; i--) board1[i][0] = board1[i - 1][0];
  for (int j = 0; j < c - 1; j++) board1[0][j] = board1[0][j + 1];
  for (int i = 0; i < x1; i++) board1[i][c - 1] = board1[i + 1][c - 1];
  for (int j = c - 1; j > 1; j--) board1[x1][j] = board1[x1][j - 1];
  board1[x1][1] = 0;
  for (int i = x2 + 1; i < r - 1; i++) board1[i][0] = board1[i + 1][0];
  for (int j = 0; j < c - 1; j++) board1[r - 1][j] = board1[r - 1][j + 1];
  for (int i = r - 1; i > x2; i--) board1[i][c - 1] = board1[i - 1][c - 1];
  for (int j = c - 1; j > 1; j--) board1[x2][j] = board1[x2][j - 1];
  board1[x2][1] = 0;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c >> t;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> board1[i][j];
      if (board1[i][j] == -1)
        if (x1 == 0)
          x1 = i;
        else
          x2 = i;
    }
  }
  while (t--) {
    diffuse();
    purify();
  }
  int ans = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (board1[i][j] <= 0) continue;
      ans += board1[i][j];
    }
  }
  cout << ans;
}
