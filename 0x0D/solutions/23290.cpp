// Authored by : sukam09
// Co-authored by : -
// http://boj.kr/430a59896f24436bb00c38ad66dfce55
#include <bits/stdc++.h>
using namespace std;

int m, s;
int x, y; // 상어 위치
// ↑, ←, ↓, →(사전순)
int dx1[4] = {-1, 0, 1, 0};
int dy1[4] = {0, -1, 0, 1};
// ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dx2[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy2[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> fish[4][4];
int smell[4][4]; // 가장 최근에 물고기 냄새가 생성된 턴, 없으면 0
int turn = 1;

bool OOB(int x, int y) {
  return x < 0 || x >= 4 || y < 0 || y >= 4;
}

// 상어가 i, j, k 방향으로 이동했을 때 제외되는 물고기의 수를 구하는 함수
int move(int i, int j, int k) {
  // 상어가 갔던 칸을 다시 방문할 경우 수를 잘못 셀 수 있으므로
  // 남은 물고기의 수를 나타내는 임시 격자를 사용
  vector<vector<int>> tmp(4, vector<int>(4));
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      tmp[i][j] = (int)fish[i][j].size();
  int cnt = 0;
  int xx = x;
  int yy = y;
  for (auto z : {i, j, k}) {
    int nx = xx + dx1[z];
    int ny = yy + dy1[z];
    if (OOB(nx, ny)) return -1;
    cnt += tmp[nx][ny];
    tmp[nx][ny] = 0;
    xx = nx;
    yy = ny;
  }
  return cnt;
}

// 제외되는 물고기가 가장 많은 방향을 구하는 함수
tuple<int, int, int> brute() {
  vector<tuple<int, int, int, int>> ret;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int cnt = move(i, j, k);
        if (cnt == -1) continue; // OOB
        // cnt를 음수로 넣어줌으로써 오름차순으로 정렬해도 되게끔 함
        ret.push_back({ -cnt, i, j, k });
      }
    }
  }
  sort(ret.begin(), ret.end());
  int cnt, i, j, k;
  tie(cnt, i, j, k) = ret[0];
  return { i, j, k };
}

void solve() {
  // 1
  vector<tuple<int, int, int>> copied;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (auto d : fish[i][j])
        copied.push_back({ i, j, d });
  // 2
  vector<int> nxt[4][4];  // 물고기가 이동을 완료한 상태의 격자
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (auto d : fish[i][j]) {
        bool chk = false;
        for (int dir = 0; dir < 8; dir++) {
          int nd = (d - dir + 8) % 8;
          int nx = i + dx2[nd];
          int ny = j + dy2[nd];
          if (OOB(nx, ny) || smell[nx][ny] != 0 || (nx == x && ny == y))
            continue;
          nxt[nx][ny].push_back(nd);
          chk = true;
          break;
        }
        // 물고기가 움직이지 않을 경우에도 똑같은 위치에 넣어줘야함
        if (!chk) nxt[i][j].push_back(d);
      }
    }
  }
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      fish[i][j] = nxt[i][j];
  // 3
  int i, j, k;
  tie(i, j, k) = brute();
  // 상어 이동
  for (auto z : { i, j, k }) {
    int nx = x + dx1[z];
    int ny = y + dy1[z];
    // 물고기가 존재할 경우에만 물고기 냄새를 남김
    if (!fish[nx][ny].empty()) {
      smell[nx][ny] = turn;
      fish[nx][ny].clear();
    }
    x = nx;
    y = ny;
  }
  // 4
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (smell[i][j] + 2 == turn)
        smell[i][j] = 0;
  // 5
  for (auto& x : copied) {
    int r, c, d;
    tie(r, c, d) = x;
    fish[r][c].push_back(d);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> s;
  for (int i = 0; i < m; i++) {
    int r, c, d;
    cin >> r >> c >> d;
    r--; c--; d--;  // 0-index
    fish[r][c].push_back(d);
  }
  cin >> x >> y;
  x--; y--;  // 0-index
  while (s--) {
    solve();
    turn++;
  }
  int ans = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      ans += (int)fish[i][j].size();
  cout << ans;
}