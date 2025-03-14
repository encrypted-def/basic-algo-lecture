// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/d1845ccb4a6345f597884753edba728e
#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[502][502];
int b[502][502];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int mx, sum;

bool oob(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

void solve(int cx, int cy, int cnt) {
  if(cnt == 4) {
    mx = max(mx, sum);
    return;
  }
  int nx, ny;
  for(int dir = 0; dir < 4; dir++) {
    nx = cx + dx[dir];
    ny = cy + dy[dir];
    if(oob(nx, ny)) continue;
    if(vis[nx][ny]) continue;
    sum += b[nx][ny];
    vis[nx][ny] = 1;
    solve(nx, ny, cnt + 1);
    if(cnt == 2)
      solve(cx, cy, cnt + 1);
    sum -= b[nx][ny];
    vis[nx][ny] = 0;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> b[i][j];
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      sum = b[i][j];
      vis[i][j] = 1;
      solve(i, j, 1);
      vis[i][j] = 0;
    }
  cout << mx << '\n';
}

/*
ㅗㅜㅓㅏ를 제외한 모든 테트로미노는
길이가 4인 루트를 찾는 백트래킹으로 얻을 수 있다.
ㅗㅜㅓㅏ는 cnt == 2에서 3번째 정사각형을 뽑은 뒤
현위치인 (cx, cy)를 인자로 다시 보내 찾을 수 있다.
해당 코드는 34-35번째 줄과 같이 구현된다.
*/