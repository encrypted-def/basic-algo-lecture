// http://boj.kr/2edfa3c97260480d81e3133d389c119f
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502]; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> board[i][j];
  int mx = 0; // 그림의 최댓값
  int num = 0; // 그림의 수
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){ // (i, j)를 시작점으로 하고 싶은 상황
      if(board[i][j] == 0 || vis[i][j]) continue; // 해당 칸이 색칠이 안된 부분(0)이거나 이미 (i, j)를 방문했을 경우 넘어감
      // (i,j)는 새로운 그림에 속해있는 시작점
      num++; // 그림의 수 1 증가
      queue<pair<int,int> > Q;
      vis[i][j] = 1; // (i,j)로 BFS를 시작하기 위한 준비
      Q.push({i,j});
      int area = 0; // 그림의 넓이
      while(!Q.empty()){
        area++; // 큐에 들어있는 원소를 하나 뺄 때 마다 넓이를 1 증가시킴
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
          if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
          vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
          Q.push({nx,ny});
        }
      }
      // (i, j)를 시작점으로 하는 BFS가 종료됨
      mx = max(mx, area); // area가 mx보다 클 경우 mx에 area를 대입. max는 STL에 정의된 함수
    }
  }
  cout << num << '\n' << mx;
}
