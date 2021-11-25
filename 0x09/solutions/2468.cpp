// Authored by : std-freejia
// Co-authored by : -
// http://boj.kr/467b23760a2e4a378e1c1fce14ed8d44
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, maxcnt, maxlimit;
int area[102][102];
int vis[102][102]; // 비에 잠긴 영역
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(int x, int y, int limit){

  queue<pair<int,int>> q;

  vis[x][y] = 1; // 방문표시
  q.push({x,y}); // 푸시

  while(!q.empty()){
    int xx = q.front().X;
    int yy = q.front().Y;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = xx + dx[i];
      int ny = yy + dy[i];

      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 정상 범위 체크
      if(vis[nx][ny] == 0 && area[nx][ny] > limit){  // 미방문, 침수되지 않음
        vis[nx][ny] = 1;  // 첫 방문이라면 방문표시
        q.push({nx, ny}); // 푸시
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) { // 0인 영역에서 시작하기
      cin >> area[i][j];
      maxlimit = max(area[i][j], maxlimit); // 잠기는 최대 높이
    }
  }

  for(int limit = 0; limit <= maxlimit; limit++) {
    for(int i = 0; i < n; i++) fill(vis[i], vis[i]+n, 0); // 방문배열 초기화
    int cnt = 0;

    for(int a = 0; a < n; a++) {
      for (int b = 0; b < n; b++) {
        if (area[a][b] > limit && vis[a][b] == 0) { // 침수 여부, 방문 여부
          bfs(a, b, limit);
          cnt++;
        }
      }
    }
    maxcnt = max(cnt, maxcnt);
  }

  cout << maxcnt;

  return 0;
}