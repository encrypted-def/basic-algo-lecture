// Authored by : yongjunleeme
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/f5754d2b4a6b48ab88efc3e9dcbb1943
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
    while (!Q.empty()) {
      auto cur = Q.front(); Q.pop();
      for (int dir = 0; dir < 8; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (dist[nx][ny] >= 0) continue;
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;        
        Q.push({nx, ny});
      }
    }
    cout << dist[xx][yy] << "\n";
  }
}
