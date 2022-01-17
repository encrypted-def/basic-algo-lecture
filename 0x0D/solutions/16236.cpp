// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/41b7439510614abcb5558af66bc68c78
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
int board[22][22];
int dist[22][22];
queue<pair<int, int>> q;
int sharkSize = 2;
int cnt = 0; // 아기 상어가 물고기를 먹은 개수
int ans = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
      if(board[i][j] == 9)
        q.push({i, j});
    }
  }

  while(1){
    bool flag = false;
    vector<pair<int, int>> fishs = {}; // 현재 아기 상어가 먹을 수 있는 크기의 물고기들
    for(int i = 0; i < n; i++)
      fill(dist[i], dist[i]+n, -1);

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        if(board[i][j] == 9){
          dist[i][j] = 0;
          board[i][j] = 0;
        }

    while(!q.empty()){
      auto cur = q.front(); q.pop();
      for(int dir = 0; dir < 4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

        if(board[nx][ny] > sharkSize || dist[nx][ny] >= 0) continue;
        if(board[nx][ny] != 0 && board[nx][ny] < sharkSize){
          fishs.push_back({nx, ny});
          flag = true;
        }
        dist[nx][ny] = dist[cur.X][cur.Y]+1;
        q.push({nx, ny});
      }
    }
    if(!flag) break;

    int mnX = fishs[0].X;
    int mnY = fishs[0].Y;
    int mnDist = dist[fishs[0].X][fishs[0].Y];

    for(int i = 1; i < fishs.size(); i++){
      int x = fishs[i].X;
      int y = fishs[i].Y;

      if(dist[x][y] < mnDist){
        mnDist = dist[x][y];
        mnX = x;
        mnY = y;
      }
      else if(dist[x][y] == mnDist){
        if(x < mnX){
          mnDist = dist[x][y];
          mnX = x;
          mnY = y;
        }
        else if(x == mnX){
          if(y < mnY){
            mnDist = dist[x][y];
            mnX = x;
            mnY = y;
          }
        }
      }
    }

    cnt++;
    if(cnt == sharkSize){
      cnt = 0;
      sharkSize++;
    }
    ans += mnDist;
    q.push({mnX, mnY});
    board[mnX][mnY] = 9;
  }
  cout << ans;
}
