// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/d3cbc0df3bc34ea0899616c42cb8f1e3
#include <bits/stdc++.h>
using namespace std;

// 체스판의 색깔((r,c)에 대해 r+c가 짝수일 경우 0에 대응, 홀수일 경우 1에 대응)에 따라 분리해서 계산

vector<pair<int, int>> board[2][20]; // board[i][j] : 색깔 i에 대해 \ 방향 대각선에 포함되는 칸들을 저장하는 vector
bool used[2][20];
int ans[2];
int N;
void bishop(int idx, int cnt, int color) {
  if (idx == 2 * N) {
    ans[color] = max(ans[color], cnt);
    return;
  }
  for (auto v : board[color][idx]) {
    int x, y;
    tie(x, y) = v;
    if (used[color][x + y]) continue;
    used[color][x + y] = true;
    bishop(idx + 1, cnt + 1, color);
    used[color][x + y] = false;
  }
  bishop(idx + 1, cnt, color);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  int d;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> d;
      if (d)
        board[(i + j + 1) % 2][N + i - j - 1].push_back({i, j});
    }
  }
  bishop(0, 0, 0);
  bishop(0, 0, 1);
  cout << ans[0] + ans[1];
}
