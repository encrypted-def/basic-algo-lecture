// Authored by : yongjunleeme
// Co-authored by : 	BaaaaaaaaaaarkingDog
// http://boj.kr/fd223e40136a4ece9b7e40f3b2491f1d
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

// 다음 잡아먹을 물고기의 (거리, 좌표 x, 좌표 y)를 반환.
// 일단 하나를 찾고 나면 그 거리를 넘어서는 순간 바로 break
tuple<int,int,int> eatfish(int x, int y){ // (x, y) : 상어의 위치
  // distance, x, y
  tuple<int, int, int> mn = {0x7f7f7f7f, 0x7f7f7f7f, 0x7f7f7f7f};
  for(int i = 0; i < n; i++)
    fill(dist[i], dist[i]+n, -1);
  queue<pair<int, int>> q;
  q.push({x, y});
  dist[x][y] = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(board[i][j] == 9){
        dist[i][j] = 0;
        board[i][j] = 0;
      }

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    if(dist[cur.X][cur.Y] >= get<0>(mn)) break;
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if(board[nx][ny] > sharkSize || dist[nx][ny] >= 0) continue;
      dist[nx][ny] = dist[cur.X][cur.Y]+1;
      if(board[nx][ny] != 0 && board[nx][ny] < sharkSize)
        mn = min(mn, {dist[nx][ny], nx, ny});      
      q.push({nx, ny});
    }
  }
  return mn;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int shark_x, shark_y;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
      if(board[i][j] == 9){
        shark_x = i;
        shark_y = j;
      }
    }
  }

  while(1){
    tuple<int, int, int> mn = eatfish(shark_x, shark_y);
    int dist, x, y;
    tie(dist, x, y) = mn;
    // 잡아먹을 수 있는 물고기가 없는 경우
    if(dist == 0x7f7f7f7f) break;
    cnt++;
    if(cnt == sharkSize){
      cnt = 0;
      sharkSize++;
    }
    ans += dist;
    q.push({x, y});
    board[x][y] = 9;
    shark_x = x;
    shark_y = y;
  }
  cout << ans;
}
