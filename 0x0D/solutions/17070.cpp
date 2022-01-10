// Authored by : sukam09
// Co-authored by : -
// http://boj.kr/e4a058bedcd44f5d945246a0fd5dfdaf

#include <bits/stdc++.h>
using namespace std;

int n;
int board[21][21];
int ans;

// 범위 밖을 벗어났는지 체크하는 함수
bool oob(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= n;
}

// 밀어서 가로 방향의 파이프로 바꿀 수 있는지 체크하는 함수
bool chkh(int x, int y) {
  return !(oob(x, y + 1) || board[x][y + 1]);
}

// 밀어서 세로 방향의 파이프로 바꿀 수 있는지 체크하는 함수
bool chkv(int x, int y) {
  return !(oob(x + 1, y) || board[x + 1][y]);
}

// 밀어서 대각선 아래 방향의 파이프로 바꿀 수 있는지 체크하는 함수
bool chkd(int x, int y) {
  return !(oob(x + 1, y + 1) || board[x][y + 1] || board[x + 1][y] || board[x + 1][y + 1]);
}

void sim(int x, int y, int dir) {
  if (x == n - 1 && y == n - 1) {
    ans++;
    return;
  }

  // dir이 0, 1, 2일 때 각각 현재 파이프의 방향이 가로, 세로, 대각선 아래를 나타냄
  if (dir == 0) {
    if (chkh(x, y)) sim(x, y + 1, 0);
    if (chkd(x, y)) sim(x + 1, y + 1, 2);
  } else if (dir == 1) {
    if (chkv(x, y)) sim(x + 1, y, 1);
    if (chkd(x, y)) sim(x + 1, y + 1, 2);
  } else {
    if (chkh(x, y)) sim(x, y + 1, 0);
    if (chkv(x, y)) sim(x + 1, y, 1);
    if (chkd(x, y)) sim(x + 1, y + 1, 2);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  cin >> n;
  for (int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> board[i][j];
  ans = 0;
  
  // (N, N)에 벽이 있으면 이동시킬 수 없음
  if (board[n - 1][n - 1]) cout << 0;
  else {
    sim(0, 1, 0);
    cout << ans;
  }
}