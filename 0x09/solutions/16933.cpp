// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/d7122ff6c350443aaafda72f0d8d8d75
#include <bits/stdc++.h>
using namespace std;

string board[1002];
int N, M, K;
bool vis[1002][1002][12];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for (int i = 0; i < N; i++)
    cin >> board[i];

  // [x좌표, y좌표, 거리, 부순 횟수]로 큐를 구성합니다.
  queue<tuple<int, int, int, int>> q;
  q.push({0, 0, 1, 0});
  vis[0][0][0] = true;
  while (q.size()) {
    auto [x, y, d, b] = q.front();
    q.pop();
    if (x == N - 1 && y == M - 1) {
      cout << d;
      return 0;
    }
    bool wait = false;
    for (int k = 0; k < 4; k++) {
      int nx = x + "1120"[k] - '1', ny = y + "2011"[k] - '1';
      if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;
      if (board[nx][ny] == '0') {
        if (vis[nx][ny][b]) continue;
        vis[nx][ny][b] = true;
        q.push({nx, ny, d + 1, b});
      } else if (b < K) {
        /*
        만약 부술 여유가 남아있고, 현재 낮이라면 당장 부수고,
        밤이라면 일단 큐에 밀어넣고 다음날을 기다립니다.
        */
        if (d % 2) {
          if (vis[nx][ny][b + 1]) continue;
          vis[nx][ny][b + 1] = true;
          q.push({nx, ny, d + 1, b + 1});
        } else
          wait = true;
      }
    }
    if (wait)
      q.push({x, y, d + 1, b});
  }
  cout << -1;
}
