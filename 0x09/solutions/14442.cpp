// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/27c2e21f68ec4c7eb9207ae99f068266
#include <bits/stdc++.h>
using namespace std;

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
    if (x == n-1 && y == m-1) {cout << dist[x][y][cnt]; return 0;}
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] == '0' && dist[nx][ny][cnt] == 0) {
        dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
        q.push({nx, ny, cnt});
      }
      // cnt가 남아 있고, 벽이고, 아직 방문하지 않았을 때
      else if (cnt && board[nx][ny] == '1' && dist[nx][ny][cnt-1] == 0) {
        dist[nx][ny][cnt-1] = dist[x][y][cnt] + 1;
        q.push({nx, ny, cnt-1});
      }
    }
  }
  cout << -1;
}
