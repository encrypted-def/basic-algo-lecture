// Authored by : yongjunleeme
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/5cd7aca68a0844afb64b3ab9ca68c569
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int MX = 1520;
int r, c, lx, ly, cnt = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int vis[MX][MX];
int visited[MX][MX];
string board[MX];
bool isPossible = false;
queue <pair<int, int>> Q;
queue <pair<int, int>> Q2;
queue <pair<int, int>> LQ;
queue <pair<int, int>> LQ2;

bool OOB(int a, int b){
  return a < 0 || a >= r || b < 0 || b >= c;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c;
  for(int i = 0; i < r; i++) cin >> board[i];
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(board[i][j] == 'L'){
        lx = i;
        ly = j;
      }
      if(board[i][j] != 'X') Q.push({i, j});
    }
  }

  LQ.push({lx, ly});
  board[lx][ly] = '.';
  vis[lx][ly] = 1;
  while(!isPossible){
    //얼음 녹이기
    while(!Q.empty()){
      auto cur = Q.front(); Q.pop();
      visited[cur.X][cur.Y] = 1;
      for(int dir = 0; dir < 4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(OOB(nx, ny) || visited[nx][ny]) continue;

        if(board[nx][ny] == 'X') Q2.push({nx, ny});
        visited[nx][ny] = 1;
      }
    }

    while(!Q2.empty()){
      auto cur = Q2.front(); Q2.pop();
      board[cur.X][cur.Y] = '.';
      Q.push({cur.X, cur.Y});
    }
    cnt++;

    //백조 찾기
    while(!LQ.empty()){
      auto cur = LQ.front(); LQ.pop();
      for(int dir = 0; dir < 4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(OOB(nx, ny) || vis[nx][ny]) continue;
        if(board[nx][ny] == 'X'){
          vis[nx][ny] = 1;
          LQ2.push({nx, ny});
          continue;
        }
        else if(board[nx][ny] == 'L'){
          isPossible = true;
          break;
        }
        vis[nx][ny] = 1;
        LQ.push({nx, ny});
      }
    }
    while (!LQ2.empty()){
      auto cur = LQ2.front(); LQ2.pop();
      LQ.push({cur.X, cur.Y});
    }
  }
  cout << cnt;
}
