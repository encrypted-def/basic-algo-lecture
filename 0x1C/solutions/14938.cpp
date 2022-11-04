// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/602ee20238604104978dd0b9ca245a34
#include <bits/stdc++.h>
using namespace std;

int n, m, r;
const int INF = 987987987;

int item[102];
bool vis[102];

int d[102][102];
int nxt[102][102];

void visit(int i, int j) {
  int cur = i;
  while(cur != j) {
    vis[cur] = 1;
    cur = nxt[cur][j];
  }
  vis[j] = 1;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> r;
  for(int i = 1; i <= n; i++) {
    int sc; cin >> sc; 
    item[i] = sc;
  }

  for(int i = 1; i <= n; i++) {
    fill(d[i], d[i] + n + 1, INF);
    d[i][i] = 0;
  }

  int x, y, dist;
  while(r--) {
    cin >> x >> y >> dist;
    d[x][y] = dist; d[y][x] = dist;
    nxt[x][y] = y; nxt[y][x] = x;
  }

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++) {
        int tmp = d[i][k] + d[k][j];
        if(tmp < d[i][j]) {
          d[i][j] = tmp;
          nxt[i][j] = nxt[i][k];
        }
      }

  int ans = 0, tmp;
  for(int i = 1; i <= n; i++){
    tmp = 0;
    fill(vis + 1, vis + n + 1, 0);

    for(int j = 1; j <= n; j++) {
      if(d[i][j] > m) continue;
      visit(i, j);
    }
    for(int j = 1; j <= n; j++)
      if(vis[j]) tmp += item[j];
    ans = max(ans, tmp);
  } 
  cout << ans;
}