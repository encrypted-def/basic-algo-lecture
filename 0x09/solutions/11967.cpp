// Authored by : haneulkimdev
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/6f7aeed00c0f47b19cbb1a1aba45323b
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[101][101];
bool vis[101][101];
vector<pair<int, int>> adj[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
bool OOB(int a, int b) { return a < 1 || a > n || b < 1 || b > n; }

bool is_conn(pair<int, int> nxt) {
  for (int dir = 0; dir < 4; dir++) {
    int nx = nxt.X + dx[dir];
    int ny = nxt.Y + dy[dir];
    if (OOB(nx, ny)) continue;
    if (vis[nx][ny]) return 1;
  }
  return 0;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    adj[x][y].push_back({a, b});
  }
  queue<pair<int, int>> Q;
  board[1][1] = 1;
  vis[1][1] = 1;
  Q.push({1, 1});
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (auto nxt : adj[cur.X][cur.Y]) {
      if (vis[nxt.X][nxt.Y]) continue;
      if (is_conn(nxt)) {
        vis[nxt.X][nxt.Y] = 1;
        Q.push({nxt.X, nxt.Y});
      }
      board[nxt.X][nxt.Y] = 1;
    }
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == 0) continue;
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) ans += board[i][j];
  cout << ans;
}
