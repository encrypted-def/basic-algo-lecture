// Authored by : qwee158
// Co-authored by : -
// http://boj.kr/f2d4f1d210bb47d2a523091250318464
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board[10][10];
int play_board[10][10];
int vis[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> v;
vector<pair<int, int>> blank;

bool oob(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m;
}
void reset_board() {
  for(int i = 0; i < n; i++) {
    fill(vis[i], vis[i]+m, 0);
    for(int j = 0; j < m; j++) {
      play_board[i][j] = board[i][j];
      if(board[i][j] == 2) {
          v.push({i, j});
          vis[i][j] = 1;
      }
    }
  }
}

int bfs() {
  while(!v.empty()) {
    int x, y; tie(x, y) = v.front(); v.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(oob(nx, ny)) continue;
      if(vis[nx][ny] || play_board[nx][ny] != 0) continue;
      play_board[nx][ny] = 2;
      vis[nx][ny] = 1;
      v.push({nx, ny});
    }
  }
  int sum = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        if(play_board[i][j] == 0) sum++;
    }
  }
  return sum;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        cin >> board[i][j];
        if(board[i][j] == 0) blank.push_back({i, j});
    }
  }
  vector<int> brute(blank.size(), 1);
  fill(brute.begin(), brute.end()-3, 0);
  int mx = 0;
  do {
    reset_board();
    // 빈 칸 중에 3개를 선택해서 벽으로 만들기
    for(int i = 0; i < brute.size(); i++) {
        if(brute[i] == 1) {
            play_board[blank[i].X][blank[i].Y] = 1;
        }
    }
    mx = max(mx, bfs());
  } while(next_permutation(brute.begin(), brute.end()));
  cout << mx;
}
