// Authored by : yongjunleeme
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/3ac8a6ad3fdf4ed3a5a88c75574c4d16
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int MX = 1520;
// lx, ly = 어떤 한 백조의 위치
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

/*
매번 O(RC)에 걸쳐 빙판을 녹이고 두 백조가 있는 곳이 연결되어 있는지 직접 BFS로 확인하는 풀이는
걸리는 날이 최악의 경우 대략 O(max(R,C))정도 될 수 있으니 1500^3이 되어 시간 초과가 발생한다.

대신 1. 얼음을 녹일 때 직전에 녹은 얼음 주변만 확인하면 된다(본문의 코드에서는 Q2를 이용해 처리)

2. (lx, ly)에서 출발한 BFS의 경우 얼음을 마주할 경우 그 얼음은 다음날 녹기 때문에 그 얼음의 위치를
임시로 기억하고 있다가 백조에 대한 BFS를 처리하는 LQ에 넣어주면 된다(본문의 코드에서는 LQ2를 이용해 처리) 

이 2가지 사실을 관찰해서 BFS를 진행하면 O(RC)에 해결할 수 있다.
*/
