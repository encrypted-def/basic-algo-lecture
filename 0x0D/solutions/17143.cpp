// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/831cf825a59b425499859792c6b0481f
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int R, C, M;
tuple<int, int, int> board1[101][101];
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
bool OOB(int a, int b) { return a < 1 || a > R || b < 1 || b > C; }

void run() {
  tuple<int, int, int> board2[101][101] = {};
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      int s, d, z;
      tie(s, d, z) = board1[i][j];
      if (z == 0) continue;
      int nx = i;
      int ny = j;
      for (int k = 0; k < s; k++) {
        if (OOB(nx + dx[d], ny + dy[d])) {
          if (d == 1)
            d = 2;
          else if (d == 2)
            d = 1;
          else if (d == 3)
            d = 4;
          else if (d == 4)
            d = 3;
        }
        nx += dx[d];
        ny += dy[d];
      }
      if (get<2>(board2[nx][ny]) < z) board2[nx][ny] = {s, d, z};
    }
  }
  for (int i = 1; i <= R; i++)
    for (int j = 1; j <= C; j++) board1[i][j] = board2[i][j];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C >> M;
  while (M--) {
    int r, c, s, d, z;
    cin >> r >> c >> s >> d >> z;
    if (d == 1 || d == 2)
      s %= (R - 1) * 2;
    else if (d == 3 || d == 4)
      s %= (C - 1) * 2;
    board1[r][c] = {s, d, z};
  }
  int ans = 0;
  for (int j = 1; j <= C; j++) {
    for (int i = 1; i <= R; i++) {
      int s, d, z;
      tie(s, d, z) = board1[i][j];
      if (z == 0) continue;
      board1[i][j] = {0, 0, 0};
      ans += z;
      break;
    }
    run();
  }
  cout << ans;
}
