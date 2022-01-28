// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/30955cc755a74a65b7126ac824054d40
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int MX = 0x7f7f7f7f;
int n, m;
int board[55][55];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> v;
queue<pair<int, int>> q;
int ans = MX;
int dist[55][55];
int vis[55][55];
int emptyCnt = 0;
bool flag = false;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
      if(board[i][j] == 0) emptyCnt++;
      if(board[i][j] == 2) v.push_back({i, j});
    }
  }
  if(!emptyCnt){
    cout << 0;
    return 0;
  }

  vector<int> brute(v.size());
  for(int i = m; i < v.size(); i++) brute[i] = 1;

  do{
    for(int i = 0; i < n; i++) fill(dist[i], dist[i]+n, -1);

    for(int i = 0; i < v.size(); i++){
      if(!brute[i]){
        q.push({v[i].X, v[i].Y});
        dist[v[i].X][v[i].Y] = 0;
      }
    }

    int emptyCnt2 = 0;
    int virusCnt = 0;
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
          virusCnt = max(virusCnt, dist[nx][ny]);
          emptyCnt2++;
        }
      }
    }
    if(emptyCnt == emptyCnt2)
      ans = min(ans, virusCnt);
  }while(next_permutation(brute.begin(), brute.end()));

  if(ans == MX) cout << -1;
  else cout << ans;
}
