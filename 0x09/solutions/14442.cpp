// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/2603556b095b406c924707a1901cc884
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string board[1002];
// x, y, 부순 횟수
int dist[1002][1002][12];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    cin >> board[i];

  // [x좌표, y좌표, 부순 횟수]로 큐를 구성한다.
  queue<tuple<int, int, int>> q;
  q.push({0, 0, 0});
  dist[0][0][0] = 1;
  while (!q.empty()) {
    auto [x, y, w] = q.front();
    q.pop();
    if (x == n - 1 && y == m - 1) {
      cout << dist[x][y][w] << '\n';
      return 0;
    }
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      // 만약 여기가 블록이라면 부순 횟수를 늘린다.
      int nw = w;
      if(board[nx][ny] == '1') nw++;
      if (nw > k || dist[nx][ny][nw] > 0) continue;
      dist[nx][ny][nw] = dist[x][y][w] + 1;
      q.push({nx, ny, nw});
    }
  }
  cout << -1;
}
/*
상태 배열에 벽을 부순 횟수까지 포함시켜야 한다.
이 문제에서는 dist의 시작값이 0이 아니라 1이어서 초기값을 -1로
초기화시킬 필요가 없었다.
*/
