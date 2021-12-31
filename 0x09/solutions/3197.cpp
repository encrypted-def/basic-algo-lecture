// Authored by : ung7497
// Co-authored by : -
// http://boj.kr/0116572bc545406998b302b63b8b452b
#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

string board[1502];
int visS[1502][1502];
int distI[1502][1502];
queue<pair<int, int>> S;
queue<pair<int, int>> tmpS;
queue<pair<int, int>> I;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int r, c;
int turn;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> r >> c;
  for (int i = 0; i < r; i++) 
    cin >> board[i];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (board[i][j] == '.') {
        visS[i][j] = -1;
        I.push({i, j});
      }
      if (board[i][j] == 'X')
        distI[i][j] = -1;
      if (board[i][j] == 'L') {
        I.push({i, j});
        if (S.empty()) {
            visS[i][j] = -2;
            S.push({i, j});
        }
      }
    }
  }
  while (!I.empty()) {
    auto cur = I.front();
    I.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if (distI[nx][ny] >= 0) continue;
      distI[nx][ny] = distI[cur.X][cur.Y] + 1;
      visS[nx][ny] = distI[nx][ny];
      I.push({nx, ny});
    }
  }
  while (!S.empty()) {
    auto cur = S.front();
    S.pop();
    int x = cur.X;
    int y = cur.Y;
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if (visS[nx][ny] > turn) {
          tmpS.push({x, y});
          continue;
      }
      if (visS[nx][ny] < -1) continue;
      if (board[nx][ny] == 'L' && visS[nx][ny] == 0) {
          cout << turn << '\n';
          return 0;
      }
      visS[nx][ny] = -2;
      S.push({nx, ny});
    }
    if (S.empty()) {
      S = tmpS;
      turn++;
      while (!tmpS.empty()) tmpS.pop();
    }
  }
  return 0;
}

/*
  얼음이 녹는 시간을 미리 구한 후, 백조가 물 탐색을 끝날 때마다 얼음을 차례대로 녹인다.
*/