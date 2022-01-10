// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/8bd0e645d39448649d2cb270c5fdac82
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> v;
queue<pair<int, int>> q;
int ans = 0;

void func(int k){
  if(k == 3){
    int tmp[10][10] = {};
    int vis[10][10] = {};
    for(int i = 0; i < v.size(); i++) q.push({v[i].X, v[i].Y});
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        tmp[i][j] = board[i][j];

    while(!q.empty()){
      auto cur = q.front(); q.pop();
      vis[cur.X][cur.Y] = 1;
      for(int dir = 0; dir < 4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(tmp[nx][ny] != 0 || vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        tmp[nx][ny] = 2;
        q.push({nx, ny});
      }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        if(tmp[i][j] == 0) cnt++;

    ans = max(ans, cnt);
    return;
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(board[i][j] != 0) continue;
      board[i][j] = 1;
      func(k+1);
      board[i][j] = 0;
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
      if(board[i][j] == 2) v.push_back({i, j});
    }
  }
  func(0);
  cout << ans;
}
