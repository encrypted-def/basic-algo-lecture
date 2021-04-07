// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/8c4c8cda5bcc473281c4cb834f7ae49b
#include <bits/stdc++.h>
using namespace std;

// board[dir][i][j][k] :  i번째 판을 시계방향으로 dir번 돌렸을 때 (j, k)의 값
int board[4][5][5][5]; 
int maze[5][5][5];

int dx[6] = {1,0,0,0,0,-1};
int dy[6] = {0,1,-1,0,0,0};
int dz[6] = {0,0,0,1,-1,0};
int solve(){
  int dist[5][5][5] = {0,};
  if(maze[0][0][0] == 0 or maze[4][4][4] == 0) return 9999;

  queue<tuple<int,int,int>> q;
  q.push({0,0,0});
  dist[0][0][0] = 1;
  while(!q.empty()){
    tuple<int,int,int> cur = q.front(); q.pop();
    for(int dir = 0; dir < 6; dir++){
      int x, y, z;
      tie(x, y, z) = cur;
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      int nz = z + dz[dir];
      if(0 > nx || 5 <= nx || 0 > ny || 5 <= ny || 0 > nz || 5 <= nz) continue;      
      if(maze[nx][ny][nz] == 0 || dist[nx][ny][nz] != 0) continue;
      if(nx == 4 && ny == 4 && nz == 4)        
        return dist[x][y][z];
      dist[nx][ny][nz] = dist[x][y][z]+1;
      q.push({nx,ny,nz});
    }
  }
  return 9999;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++)
      for(int k = 0; k < 5; k++)
        cin >> board[0][i][j][k];
    
    for(int j = 0; j < 5; j++)
      for(int k = 0; k < 5; k++)
        board[1][i][j][k] = board[0][i][4-k][j];        
      
    for(int j = 0; j < 5; j++)
      for(int k = 0; k < 5; k++)
        board[2][i][j][k] = board[1][i][4-k][j]; 

    for(int j = 0; j < 5; j++)
      for(int k = 0; k < 5; k++)
        board[3][i][j][k] = board[2][i][4-k][j];      
  }

  int order[5] = {0,1,2,3,4}; // 판을 쌓는 순서
  int ans = 9999;
  do{
    for(int tmp = 0; tmp < 1024; tmp++){
      int brute = tmp; // 5개의 판에 대해 dir을 정해주기 위한 변수
      for(int i = 0; i < 5; i++){
        int dir = brute % 4; // brute & 3 이라고 멋있게 쓸 수도 있음
        brute /= 4; // brute >>= 2 라고 멋있게 쓸 수도 있음
        for(int j = 0; j < 5; j++)
          for(int k = 0; k < 5; k++)
            maze[i][j][k] = board[dir][order[i]][j][k];        
      }
      ans = min(ans,solve());
    }
  }while(next_permutation(order,order+5));

  if(ans == 9999) ans = -1;
  cout << ans;
}
