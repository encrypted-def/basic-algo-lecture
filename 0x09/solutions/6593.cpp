// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/eee7356385264e9195a2b641b856fe67
#include <bits/stdc++.h>
using namespace std;
const int MX = 31;
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};
int l, r, c;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(1){
    cin >> l >> r >> c;
    if(l == 0 && r == 0 && c == 0) break;
    queue<tuple<int,int,int>> Q;
    char board[MX][MX][MX];
    int dist[MX][MX][MX];
    bool isEscape = false;

    for(int i = 0; i < l; i++)
      for(int j = 0; j < r; j++) fill(dist[i][j], dist[i][j] + c, 0);

    for(int i = 0; i < l; i++){
      for(int j = 0; j < r; j++){
        for(int k = 0; k < c; k++){
          cin >> board[i][j][k];
          if(board[i][j][k] == 'S'){
            Q.push({i,j,k});
            dist[i][j][k] = 0;
          }
          else if(board[i][j][k] == '.') dist[i][j][k] = -1;
        }
      }
    }

    while(!Q.empty()){
      if(isEscape) break;
      auto cur = Q.front(); Q.pop();
      int curH, curX, curY;
      tie(curH, curX, curY) = cur;
      for(int dir = 0; dir < 6; dir++){
        int nh = curH + dh[dir];
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c || nh < 0 || nh >= l) continue;
        if(board[nh][nx][ny] == '#' || dist[nh][nx][ny] > 0) continue;

        dist[nh][nx][ny] = dist[curH][curX][curY] + 1;
        if(board[nh][nx][ny] == 'E'){
          cout << "Escaped in " << dist[nh][nx][ny] << " minute(s).\n";
          isEscape = true;
          break;
        }
        Q.push({nh,nx,ny});
      }
    }
    if(!isEscape) cout << "Trapped!" << "\n";
  }
}
