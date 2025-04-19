// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/4bfcd3c7db0441df9e6c8317af3672ab
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int d[505][505];
int board[505][505];
int n;

bool OOB(int i, int j){
  return i < 0 || i >= n || j < 0 || j >= n;
}

int go(int x, int y){
  if(d[x][y] != -1)
    return d[x][y];
  
  d[x][y] = 1;
  for(int dir = 0; dir < 4; dir++){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(OOB(nx, ny) || board[x][y] >= board[nx][ny]) continue;
    d[x][y] = max(d[x][y], go(nx, ny) + 1);
  }
  return d[x][y];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
      d[i][j] = -1;
    }
  }
  
  int mx = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      mx = max(mx, go(i, j));
  }

  cout << mx << '\n';
}
