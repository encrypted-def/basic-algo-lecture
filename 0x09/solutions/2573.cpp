// Authored by : std-freejia
// Co-authored by : -
// http://boj.kr/54d4c0432f9c4dee93956353098fd54a
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m, year, areacnt;
bool goflag = true;
int area[303][303];
int vis[303][303];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool check(int i, int j) {
  return (i >= 0 && i < n && j >= 0 && j < m);
}

void initvis(){
  for(int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);
}

int melting(){ // 녹는 높이 계산해서 0이 된 칸의 개수를 센다

  int zero[303][303] = {0};
  int zerocnt = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(area[i][j] == 0) continue;
      for(int z = 0; z < 4; z++){ // 주변의 0의 개수를 센다
        int nx = i + dx[z];
        int ny = j + dy[z];
        if(!check(nx, ny)) continue; // 유효 인덱스 체크
        if(area[nx][ny] == 0) zero[i][j]++;
      }
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      area[i][j] = area[i][j]- zero[i][j];
      if(area[i][j] > 0) continue;
      area[i][j] = 0; zerocnt++; // 0이 된 칸의 개수
    }
  }

  return zerocnt;
}

void bfs(int x, int y){

  queue<pair<int,int> > qu; // {좌표 x, y}

  vis[x][y] = 1; // 현재 위치 방문
  qu.push({x, y});

  while(!qu.empty()){
    int curx = qu.front().X;
    int cury = qu.front().Y;
    qu.pop();

    for(int i = 0; i < 4; i++){
      int nx = curx + dx[i];
      int ny = cury + dy[i];
      if(!check(nx, ny) || vis[nx][ny] == 1 || area[nx][ny] <= 0) continue; // 정상 범위, 첫 방문, 이동가능 체크
      vis[nx][ny] = 1; // 방문표시
      qu.push({nx, ny}); // 이동
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) {
      cin >> area[i][j];
    }
  }

  while(goflag){

    // 빙산 녹이기. 다 녹았으면 탈출.
    if(melting() == (m*n)){ year = 0; break; }

    year++; // 1년 추가
    initvis(); // 방문배열 초기화
    areacnt = 0; // 덩어리 개수

    for(int i = 0; i < n; i++) {
      for (int j = 0; j < m && goflag; j++) {
        if(area[i][j] <= 0 || vis[i][j]) continue; // 첫방문, 높이존재 여부
        bfs(i, j);
        areacnt++;
        if(areacnt > 1){ goflag = false; break;} // 덩어리 2개 이상면 탈출
      }
    }
  }

  cout << year;
  return 0;
}