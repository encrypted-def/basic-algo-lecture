// Authored by : std-freejia
// Co-authored by : -
// http://boj.kr/bfe3758c68d747a7ba7b03a8bca17483
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m, x, y, a, b, answer;
int room[103][103];
int slist[20002][5]; // 현재 위치좌표와 스위치 좌표 목록
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int,int>> qu;

bool checkrange(int i, int j){ // 유효범위
  return (i >= 1 && i <= n && j >= 1 && j <= n);
}

int bfs(){

  bool vis[103][103] = {false};
  int cnt = 0;
  vis[1][1] = true;
  qu.push({1,1});

  while(!qu.empty()){

    int cx = qu.front().X;
    int cy = qu.front().Y;
    qu.pop();

    for(auto li : slist){ // 현재위치 (cx, cy)에서 스위치로 켤 수 있는 방 불켜기.
      int xx = li[0], yy = li[1], aa = li[2], bb = li[3];
      if(xx == cx && yy == cy && !room[aa][bb]){
        room[aa][bb] = 1;
        cnt++;
      }
    }

    for(int i = 0; i < 4; i++){
      int nx = dx[i] + cx;
      int ny = dy[i] + cy;
      if(!checkrange(nx, ny) || !room[nx][ny] || vis[nx][ny]) continue; // 불켜져 있고 방문하지 않은 방으로 이동
      qu.push({nx,ny});
      vis[nx][ny] = true;
    }
  }
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> x >> y >> a >> b;
    slist[i][0] = x; slist[i][1] = y;
    slist[i][2] = a; slist[i][3] = b;
  }

  room[1][1] = 1; // 시작점 불 켜기
  answer = 1;

  while (1){
    int newcnt = bfs();
    answer += newcnt;
    if(newcnt == 0) break;
  }
  cout << answer;
  return 0;
}