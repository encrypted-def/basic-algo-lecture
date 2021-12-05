// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/d53c8adf44dd46c2a3d5386973e32262
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int MX = 102;
int board[MX][MX];
int vis[MX][MX];
int dist[MX][MX];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int n, cnt = 0;
queue<pair<int,int>> Q;
vector<int> ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) cin >> board[i][j];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(board[i][j] == 0 || vis[i][j]) continue;
      cnt++;
      vis[i][j] = 1;
      board[i][j] = cnt;
      Q.push({i,j});
      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[nx][ny] || board[nx][ny] == 0) continue;
            board[nx][ny] = cnt;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
      }
    }
  }
  for(int i = 0; i < n; i++)
    fill(dist[i], dist[i] + n, -1);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(board[i][j] != 0){
        Q.push({i,j});
        dist[i][j] = 0;
        while(!Q.empty()){
          auto cur = Q.front(); Q.pop();
          for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[i][j] < board[nx][ny]){
              ans.push_back(dist[cur.X][cur.Y]);
              break;
            }
            if(dist[nx][ny] >= 0 || board[i][j] == board[nx][ny]) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
          }
        }
        for(int i = 0; i < n; i++)
          fill(dist[i], dist[i] + n, -1);
      }
    }
  }
  cout << *min_element(ans.begin(), ans.end());
}
