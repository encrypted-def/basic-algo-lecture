// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : jihwan0123
// http://boj.kr/b4a6eb773dd245e88475502d0b25d168
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[8][8];
int n, m, ans;
int free_cells = 0;
queue<pair<int, int>> virus;  // 바이러스
vector<pair<int, int>> frees; // 빈칸
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// 바이러스가 전파된 칸의 수를 반환
int bfs() {
  queue<pair<int, int>> q;
  bool vis[8][8] = {};
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(board[i][j] == 2) q.push({i, j});
    }
  }
  int ret = 0;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    ret++;
    for (int i = 0; i < 4; i++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (board[nx][ny] != 0 || vis[nx][ny]) continue;
      vis[nx][ny] = 1;
      q.push({nx, ny});      
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 0) {     // 빈 칸 개수와 좌표 저장
        free_cells++;
        frees.push_back({i, j});
      } else if (board[i][j] == 2) // 바이러스 좌표 저장
        virus.push({i, j});
    }
  }
  for(int i = 0; i < frees.size(); i++){
    board[frees[i].X][frees[i].Y] = 1;
    for(int j = i + 1; j < frees.size(); j++){
      board[frees[j].X][frees[j].Y] = 1;
      for(int k = j + 1; k < frees.size(); k++){
        board[frees[k].X][frees[k].Y] = 1;
        // 바이러스 퍼진 개수 체크
        int tmp = bfs();
        // 안전영역 = 빈칸 - 바이러스 퍼진 칸, 3을 빼는 이유는 벽을 3개 세웠으므로.
        ans = max(free_cells - 3 - tmp + (int)virus.size(), ans);
        board[frees[k].X][frees[k].Y] = 0;
      }
      board[frees[j].X][frees[j].Y] = 0;
    }
    board[frees[i].X][frees[i].Y] = 0;
  }  
  cout << ans;
}
/*
3중 for문을 이용해 빈칸 중에서 3개씩 벽으로 바꿔보면서 최대 크기 계산
*/
