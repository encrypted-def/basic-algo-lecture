// Authored by : yongjunleeme
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/c0eb9e2e9bbe4ebeb386e2635ba01a68
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int MX = 0x7f7f7f7f;
int n, m;
int board[55][55];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> place; // 바이러스가 있을 수 있는 칸
queue<pair<int, int>> q;
int ans = MX;
int dist[55][55];
int emptyCnt = 0; // 빈 칸의 수
vector<int> brute; // next_permutation을 돌리기 위한 배열
int bfs(){
  for(int i = 0; i < n; i++) fill(dist[i], dist[i]+n, -1);

  for(int i = 0; i < place.size(); i++){
    if(brute[i]) continue;
    q.push({place[i].X, place[i].Y});
    dist[place[i].X][place[i].Y] = 0;
  }

  int num = 0;
  int times = 0;
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if(board[nx][ny] == 1 || dist[nx][ny] >= 0) continue;
      q.push({nx, ny});
      dist[nx][ny] = dist[cur.X][cur.Y]+1;

      if(board[nx][ny] != 2){
        times = dist[nx][ny];
        num++;
      }
    }
  }
  if(emptyCnt == num) return times;
  return MX;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
      if(board[i][j] == 0) emptyCnt++;
      if(board[i][j] == 2) place.push_back({i, j});
    }
  }
  brute.resize(place.size());
  fill(brute.begin() + m, brute.end(), 1);
  do{
    ans = min(ans, bfs());
  }while(next_permutation(brute.begin(), brute.end()));
  if(ans == MX) cout << -1;
  else cout << ans;
}
