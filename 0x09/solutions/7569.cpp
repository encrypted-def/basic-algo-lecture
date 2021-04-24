// Authored by : BueVonHun
// Co-authored by : -
// http://boj.kr/2f20289998684fcda4d28da3fd3a8a26
#include <bits/stdc++.h>
#include "iostream"
#include "queue"
#include "tuple"

using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int board[1003][1003][1003];
int dist[1003][1003][1003];
queue<tuple<int, int, int>> Q;
int m, n, h;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> m >> n >> h;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
	  for (int k = 0; k < m; k++) {
	    int tmp;
	    cin >> tmp;
		board[j][k][i] = tmp;
		if (tmp==1) Q.push({j, k, i});
        if (tmp==0) dist[j][k][i] = -1;
	  }
    }
  }

  while (!Q.empty()) {
    auto cur = Q.front(); Q.pop();
	int curX = get<0>(cur);
    int curY = get<1>(cur);
    int curZ = get<2>(cur);
    for (int dir = 0; dir < 6; dir++) {
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      int nz = curZ + dz[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
      if (dist[nx][ny][nz] >= 0) continue;
      dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
      Q.push({nx, ny, nz});
    }
  }

  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (dist[j][k][i]==-1) {
          cout << -1 << "\n";
          return 0;
        }
        ans = max(ans, dist[j][k][i]);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
