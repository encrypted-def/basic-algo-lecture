// Authored by : sukam09
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/953959bfe6ae4931a1e1961286815365
#include <bits/stdc++.h>
using namespace std;

int n;
int board[21][21];
int ans;
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};

// 범위 밖을 벗어났는지 체크하는 함수
bool oob(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= n;
}

void sim(int x, int y, int before_dir) {
  if (x == n - 1 && y == n - 1) {
    ans++;
    return;
  }

  for(int dir = 0; dir < 3; dir++){
    // 45도 제한 조건
    if(before_dir == 0 && dir == 2) continue;
    if(before_dir == 2 && dir == 0) continue;
    
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(oob(nx, ny) || board[nx][ny]) continue;
    // 대각선으로 이동할 때에 한해 2칸을 더 고려해야 함
    if(dir == 1){
      if(board[nx][y] || board[x][ny]) continue;
    }
    sim(nx, ny, dir);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  cin >> n;
  for (int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> board[i][j];

  sim(0, 1, 0);
  cout << ans;
}
