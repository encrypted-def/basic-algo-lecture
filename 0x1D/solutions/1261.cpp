// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/d80082187a144148ac6826a99624c2e0
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;
bool b[102][102];
int d[102][102];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int solve(){
  priority_queue< tuple<int, int, int>,
                  vector<tuple<int, int, int>>,
                  greater<tuple<int, int, int>> > pq;
  d[1][1] = 0;
  pq.push({0, 1, 1});
  while(!pq.empty()){
    int cw, cx, cy;
    tie(cw, cx, cy) = pq.top(); pq.pop();
    if(d[cx][cy] != cw) continue;

    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx > n || nx < 1) continue;
      if(ny > m || ny < 1) continue;
      int nw = cw + b[nx][ny];
      if(nw < d[nx][ny]) {
        d[nx][ny] = nw;
        pq.push({nw, nx, ny});
      }
    }
  }
  return d[n][m];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> m >> n;
  for(int i = 1; i <= n; i++){
    string str; cin >> str;
    for(int j = 1; j <= m; j++)
      b[i][j] = str[j-1] - '0';
  }
  for(int i = 1; i <= n; i++)
    fill(d[i] + 1, d[i] + m + 1, INF);

  cout << solve();
}