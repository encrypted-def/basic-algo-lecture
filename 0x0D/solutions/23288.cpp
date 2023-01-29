// Authored by : HJPark
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/0b99159aaaba43379606d5aefce0b753
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int board[22][22];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dir = 0;               // 동 남 서 북
int cur_r = 1, cur_c = 1;  // 현 위치
int dice[6] = {1, 2, 3, 4, 5, 6};
int ans = 0;

bool OOB(int r, int c) {
  return r <= 0 || r > n || c <= 0 || c > m;
}

void next_dir() {
  int dice_bottom = dice[5];
  if (board[cur_r][cur_c] < dice_bottom)
    dir = (dir + 1) % 4;
  else if (board[cur_r][cur_c] > dice_bottom)
    dir = (dir + 3) % 4;
  
  if (OOB(cur_r + dx[dir], cur_c + dy[dir]))
    dir = (dir + 2) % 4;
}

void get_score() {
  int tile = 1;
  bool vis[22][22] = {};
  queue<pair<int, int>> q;
  q.push({cur_r, cur_c});
  vis[cur_r][cur_c] = 1;

  while (!q.empty()) {
    pair<int, int> pos = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nxt_r = pos.first + dx[i];
      int nxt_c = pos.second + dy[i];
      if (!OOB(nxt_r, nxt_c) && !vis[nxt_r][nxt_c] && board[nxt_r][nxt_c] == board[cur_r][cur_c]) {
        q.push({nxt_r, nxt_c});
        vis[nxt_r][nxt_c] = 1;
        tile++;
      }
    }
  }

  ans += tile * board[cur_r][cur_c];
}

void move() {
  int tmp[6];
  copy(begin(dice), end(dice), begin(tmp));

  if (dir == 0) {  // 동
    dice[0] = tmp[3];
    dice[2] = tmp[0];
    dice[5] = tmp[2];
    dice[3] = tmp[5];
  } else if (dir == 1) {  // 남
    dice[0] = tmp[1];
    dice[4] = tmp[0];
    dice[5] = tmp[4];
    dice[1] = tmp[5];
  } else if (dir == 2) {  // 서
    dice[0] = tmp[2];
    dice[2] = tmp[5];
    dice[5] = tmp[3];
    dice[3] = tmp[0];
  } else if (dir == 3) {  // 북
    dice[0] = tmp[4];
    dice[4] = tmp[5];
    dice[5] = tmp[1];
    dice[1] = tmp[0];
  }

  cur_r += dx[dir];
  cur_c += dy[dir];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> board[i][j];
    }
  }

  while (k--) {
    move();
    get_score();
    next_dir();
  }

  cout << ans;
}

/*
현 위치와 주사위 전개도를 갱신한다.
queue를 이용한 bfs를 통해 같은 수를 가진 타일 수를 구한 뒤 점수를 계산한다.
다음 이동 방향 갱신한다.
만약 다음에 갱신된 방향으로 이동 시 지도의 범위를 벗어난다면, 이동 방향을 반대로 해 준다.
*/
