// Authored by : jihwan0123
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/c6dff411258544ce8393f745f463df33
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
pair<int,int> red, blue; // 빨간 구슬과 파란 구슬의 위치
string board[11];
// dist[a][b][c][d] : 빨간 구슬이 (a, b)이고 파란 구슬이 (c, d)에 위치한 상황에 도달하기 위한 동작의 횟수
int dist[11][11][11][11]; 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// red_x, red_y : 빨간 구슬 좌표, blue_x, blue_y : 파란 구슬 좌표
int bfs() {
  queue<tuple<int, int, int, int>> q;
  q.push({red.X, red.Y, blue.X, blue.Y});
  dist[red.X][red.Y][blue.X][blue.Y] = 0;
  while (!q.empty()) {
    int rx, ry, bx, by;
    tie(rx, ry, bx, by) = q.front();
    q.pop();
    int cnt = dist[rx][ry][bx][by];
    // 10번 넘게 탈출 못하면 -1
    if (cnt >= 10)
      return -1;
    // 4방향으로 기울이기
    for (int i = 0; i < 4; i++) {
      int n_rx = rx, n_ry = ry, n_bx = bx, n_by = by;

      // Blue 이동, 가장자리에 모두 '#'이 있다는 조건으로 인해 OOB를 체크하지 않아도 됨. #나 O의 앞에서 정지함.
      while (board[n_bx + dx[i]][n_by + dy[i]] == '.'){
        n_bx += dx[i];
        n_by += dy[i];
      }
      // Blue가 탈출했다면 실패이므로 continue
      if(board[n_bx + dx[i]][n_by + dy[i]] == 'O') continue;

      // Red 이동
      while (board[n_rx + dx[i]][n_ry + dy[i]] == '.'){
        n_rx += dx[i];
        n_ry += dy[i];
      }
      // Red가 탈출했다면 종료, 바로 정답을 반환
      if(board[n_rx + dx[i]][n_ry + dy[i]] == 'O') return cnt+1;

      // Red, Blue가 겹쳐진 경우 늦게 출발한 구슬을 한칸 뒤로 이동
      if ((n_rx == n_bx) && (n_ry == n_by)) {
        if (i == 0) // 위쪽
          ry < by ? n_ry-- : n_by--;
        else if (i == 1) // 오른쪽
          rx < bx ? n_rx-- : n_bx--;
        else if (i == 2) // 아래쪽
          ry > by ? n_ry++ : n_by++;
        else // 왼쪽
          rx > bx ? n_rx++ : n_bx++;
      }
      // 이미 (n_rx, n_ry, n_bx, n_by)를 방문한 적이 있다면 continue
      if (dist[n_rx][n_ry][n_bx][n_by] != -1) continue;
      dist[n_rx][n_ry][n_bx][n_by] = cnt + 1;
      q.push({n_rx, n_ry, n_bx, n_by});
    }
  }
  return -1;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // 거리 배열 초기화
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
      for(int k = 0; k < 10; k++)
        fill(dist[i][j][k], dist[i][j][k]+10, -1);
  
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> board[i];
    for (int j = 0; j < m; j++) {      
      if (board[i][j] == 'B'){
        blue = {i, j};
        board[i][j] = '.';
      }
      else if (board[i][j] == 'R'){
        red = {i, j};
        board[i][j] = '.';
      }
    }
  }
  
  cout << bfs();
}
/*
빨간 구슬과 파란 구슬의 좌표를 가지고 4차원에서 BFS를 돌리면 된다. O(N^2M^2)에 동작한다.
최대 10번이라는 제한이 있기 때문에 O(4^10)의 백트래킹으로도 통과가 가능하다.
*/
