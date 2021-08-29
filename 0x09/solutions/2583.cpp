// Authored by : 0silver00
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/d0c205b6ead644d896fec013b6e64129
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int m, n, k;
int board[102][102];
int vis[102][102];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n >> k;
  while (k--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int j = y1; j < y2; j++)
      for (int k = x1; k < x2; k++)
        board[j][k] = 1;
  }

  int count = 0;
  vector<int> ans;
	
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 1 || vis[i][j] == 1)
        continue;
      queue<pair<int, int>> Q;
      vis[i][j] = 1;
      Q.push({ i, j });
      int width = 1;
      count++;
      while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
          if (board[nx][ny] == 1 || vis[nx][ny] == 1)
            continue;
          Q.push({ nx, ny });
          vis[nx][ny] = 1;
          width++;
        }
      }
      ans.push_back(width);
    }
  }
  sort(ans.begin(), ans.end());

  cout << count << '\n';
  for (int i : ans)
    cout << i << ' ';

  return 0;  
}
