// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/7a74fe31a87c42ffbaa39e94711ae557
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, k;
int a, b, c, l;
char d;
int board[105][105]; // 1: 뱀, 2: 사과
int second = 0;
int dx[4] = {1, 0, -1, 0};  // [1][0]: 아래, [0][1]: 오른쪽, [-1][0]: 위, [0][-1]: 왼쪽
int dy[4] = {0, 1, 0, -1};
deque<pair<int, int>> dq;
queue<pair<int, char>> switchDir;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cin >> k;
  while(k--){
    cin >> a >> b;
    // 사과
    board[a][b] = 2;
  }

  cin >> l;
  while(l--){
    // 방향전환
    cin >> c >> d;
    switchDir.push({c, d});
  }

  dq.push_front({1,1});
  int dir = 1;

  while(1){
    dir %= 4;

    auto cur = dq.front();
    board[cur.X][cur.Y] = 1;
    second++;

    int nx = cur.X + dx[dir];
    int ny = cur.Y + dy[dir];

    if(nx < 1 || nx > n || ny < 1 || ny > n) break;
    if(board[nx][ny] == 1) break;

    if(board[nx][ny] != 2) {
      auto tail = dq.back();
      board[tail.X][tail.Y] = 0;
      dq.pop_back();
    }

    auto sd = switchDir.front();
    if(sd.X == second){
      if(sd.Y == 'L') dir += 1;
      else if(sd.Y == 'D') dir += 3;
      switchDir.pop();
    }
    dq.push_front({nx, ny});
  }
  cout << second;
}
