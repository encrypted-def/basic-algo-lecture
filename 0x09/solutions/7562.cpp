// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/4bdeb8c2571e473b8dc0d74785f19d5a
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dist[305][305];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int t, n, x, y, xx, yy;
queue <pair<int, int >> Q;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
    cin >> x >> y;
    dist[x][y] = 0;
    Q.push({x, y});
    cin >> xx >> yy;
    if (x == xx && y == yy) {
      cout << 0 << "\n";
      continue;
    }
    while (!Q.empty()) {
      auto cur = Q.front(); Q.pop();
      for (int dir = 0; dir < 8; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (dist[nx][ny] >= 0) continue;
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        if (nx == xx && ny == yy) {
          cout << dist[nx][ny] << "\n";
          continue;
        }
        Q.push({nx, ny});
      }
    }
  }
}

