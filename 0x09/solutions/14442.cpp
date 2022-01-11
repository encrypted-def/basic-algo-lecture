// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/ef352cb178c94bb4afe1f82079ceab65
#include <bits/stdc++.h>
using namespace std;

int N, M, K;
string board[1002];
// x, y, 부순 횟수
bool vis[1002][1002][12];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for (int i = 0; i < N; i++)
    cin >> board[i];

  // [x좌표, y좌표, 거리, 부순 횟수]로 큐를 구성한다.
  queue<tuple<int, int, int, int>> q;
  q.push({0, 0, 0, 0});
  vis[0][0][0] = true;
  while (q.size()) {
    auto [x, y, d, b] = q.front();
    q.pop();
    if (x == N - 1 && y == M - 1) {
      cout << d + 1 << '\n';
      return 0;
    }
    vis[x][y][b] = true;
    for (int k = 0; k < 4; k++) {
      int nx = x + "1120"[k] - '1', ny = y + "2011"[k] - '1';
      if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;
      // 만약 여기가 블록이라면 부순 횟수를 늘린다.
      int nb = b + (board[nx][ny] == '1');
      if (K < nb) continue;
      if (vis[nx][ny][nb]) continue;
      vis[nx][ny][nb] = true;
      q.push({nx, ny, d + 1, nb});
    }
  }
  cout << -1;
}