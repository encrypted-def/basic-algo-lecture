// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/5391b877c86d44c98e183321064cbdea
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int shk = 17;

vector<vector<pair<int, int>>> board(4);
vector<pair<int, int>> coord;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

bool oob(int x, int y) {
  return x >= 4 || x < 0 || y >= 4 || y < 0;
}

int solve(vector<vector<pair<int, int>>> b, vector<pair<int, int>> co) {
  for (int no = 1; no <= 16; no++) {
    auto [cx, cy] = co[no];
    if (cx == -1 || cy == -1) continue;
    int dir = b[cx][cy].Y;
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    while (oob(nx, ny) || b[nx][ny].X == shk) {
      dir = (dir + 1) % 8;
      nx = cx + dx[dir];
      ny = cy + dy[dir];
    }
    b[cx][cy].Y = dir;

    co[no] = {nx, ny};
    co[b[nx][ny].X] = {cx, cy};
    b[cx][cy] = b[nx][ny];
    b[nx][ny] = {no, dir};
  }

  int ans = 0;
  auto [cx, cy] = co[shk];
  int dir = b[cx][cy].Y;
  for (int p = 1; p <= 3; p++) {
    int nx = cx + p * dx[dir];
    int ny = cy + p * dy[dir];
    if (oob(nx, ny) || !b[nx][ny].X) continue;

    vector<vector<pair<int, int>>> tmpb = b;
    vector<pair<int, int>> tmpco = co;
    int no = tmpb[nx][ny].X;
    tmpb[nx][ny].X = shk;
    tmpco[shk] = {nx, ny};
    tmpco[no] = {-1, -1};
    tmpb[cx][cy] = {0, 0};
    ans = max(ans, no + solve(tmpb, tmpco));
  }
  return ans;
}

void setup() {
  coord.resize(19);
  for (int i = 0; i < 4; i++) {
    board[i].resize(4);
    for (int j = 0; j < 4; j++) {
      int no, dir; cin >> no >> dir;
      board[i][j] = {no, dir - 1};
      coord[no] = {i, j};
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setup();
  int no = board[0][0].X;
  board[0][0].X = shk;
  coord[no] = {-1, -1};
  coord[shk] = {0, 0};
  cout << no + solve(board, coord) << '\n';
}
/*
0은 물고기가 없는 칸을 의미하며, 1부터 16까지의 수를 물고기의 번호로 둔다.
17은 상어의 번호로 지정하여 구현한다.

setup 함수: 58-68번째 줄
- 초기 정보를 board와 coord 벡터에 저장하며, board[x][y]에는 번호와 방향이 pair로 저장된다(64번째 줄).
- coord[no]는 물고기 또는 상어의 위치를 1부터 17까지 번호를 통해 인덱싱한다(65번째 줄).

board와 coord 벡터를 solve 함수에 전달하며 백트래킹한다.

solve 함수: 18-56번째 줄
  1. 물고기 이동 구현
  - 넘겨받은 상태(벡터 b와 co에 복사)에 대해 상어가 먹을 수 있는 최대 물고기 번호를 반환한다.
  - 1번부터 16번 물고기를 이동시키는 for문: 19-36번째 줄.
  - 먹힌 고기는 co 벡터의 값을 {-1, -1}로 설정할 것이므로, 이에 해당하면 다음 번호를 확인한다(21번째 줄).
  - 다음 위치가 판을 벗어나거나 상어가 위치한 경우에는 방향을 바꾸고 nx, ny를 갱신한다(25-29번째 줄).
    이후 얻은 방향을 현위치의 dir 값으로 갱신한다(30번째 줄).
  - cx, cy에 위치한 정보와 nx, ny에 위치한 정보를 교환한다(32-35번째 줄).

  2. 상어 이동 및 백트래킹 구현
  - 상어의 위치와 방향을 가져온다. 판의 제약사항으로 인해 상어가 최대 3칸까지 이동이 가능하므로,
    좌표의 증가량 p를 최대 3까지만 설정한다(41번째 줄).
  - 문제 조건에 따라 비어있는 칸에는 상어가 가지 못하므로, 판을 벗어나는 경우와 함께 경우에서 배제한다(44번째 줄).
  - 이후 tmpb와 tmpco에 b와 co 벡터를 복사하고, 상어를 배치한다(46-52번째 줄).
  - 상어는 해당 물고기의 방향을 유지하며 위치만 가져간다(49-50번째 줄).
  - 상어에게 먹힌 물고기는 위치를 -1, -1로 바꾸고, no은 0으로 바꿔 비어있음을 나타낸다(51-52번째 줄). 
  - 이후 갱신된 tmpb와 tmpco를 인자로 념겨준 solve 함수와 먹은 물고기 번호의 합을 ans 값과 비교하며 갱신한다(53번째 줄).
  - solve함수는 최종적으로 갱신된 가장 큰 ans 값을 반환한다(55번쨰 줄).
*/