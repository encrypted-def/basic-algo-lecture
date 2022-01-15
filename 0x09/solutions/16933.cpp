// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/09c6d8f2343c4ffa875171b161d2fca3
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char board[1005][1005];
int dist[1005][1005][13];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, k;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> board[i][j];

  queue<tuple<int, int, int>> q;
  dist[0][0][k] = 1;
  q.push({0, 0, k});
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    int x, y, cnt;
    tie(x, y, cnt) = cur;
    if (x == n-1 && y == m-1) { cout << dist[x][y][cnt]; return 0; }
    bool sleep = false;
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] == '0' && dist[nx][ny][cnt] == 0) {
        dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
        q.push({nx, ny, cnt});
      }
      else if (cnt && board[nx][ny] == '1' && dist[nx][ny][cnt-1] == 0) {
        // 낮이면 벽을 부수고 진행
        if (dist[x][y][cnt] % 2) {
            dist[nx][ny][cnt-1] = dist[x][y][cnt] + 1;
            q.push({nx, ny, cnt-1});
        }
        // 밤이면 sleep에 표시
        else sleep = true;
      }
    }
    // 인접한 노드를 돌고 나서 sleep이면 현재 노드에 +1
    if (sleep) {
      dist[x][y][cnt]++;
      q.push({x, y, cnt});
    }
  }
  cout << -1;
}
