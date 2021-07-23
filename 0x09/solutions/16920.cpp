// Authored by : qhsl1213
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/2adb444701754f48baa8b965bb9a9b05
#include <bits/stdc++.h>
using namespace std;
int canExtend[1000][1000];
int step[10];
int area[10];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<tuple<int, int, int>> q[10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, P;
  cin >> N >> M >> P;
  // 각 플레이어의 이동 제한 횟수 입력
  for(int i=1; i<=P; i++)
    cin >> step[i];
  // 맵 입력
  char ch;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> ch;
      if(ch == '.') canExtend[i][j] = 1;
      else if(ch == '#') canExtend[i][j] = 0;
      else{
        canExtend[i][j] = 0;
        q[ch - '0'].push({i, j, 0}); // 각 플레이어의 초기 영토 기록
        area[ch - '0'] += 1;
      }
    }
  }
  // 게임 시작
  while(1){
    bool isExtend = 0;
    // 1~P번 플레이어의 순차적인 영토 확장
    for (int i = 1; i <= P; i++) {
      queue<tuple<int,int,int>> nextq; // 다음 턴에 확장을 고려할 영토 기록
      while (!q[i].empty()) {
        int curx, cury, curstep;
        tie(curx, cury, curstep) = q[i].front();
        q[i].pop();
        if (curstep >= step[i]) {
          nextq.push({curx, cury, 0});
          continue;
        }
        for (int dir = 0; dir < 4; dir++) {
          int x = curx + dx[dir], y = cury + dy[dir];
          if (x < 0 || x >= N || y < 0 || y >= M) continue;
          if (!canExtend[x][y]) continue;
          q[i].push({x, y, curstep+1});
          canExtend[x][y] = 0;
          area[i]++;
          isExtend = 1;
        }
      }
      q[i] = nextq;
    }
    // 아무도 영토를 확장하지 못하여 게임이 끝났는지 확인
    if(!isExtend) break;
  }
  // 각 플레이어의 영토 출력
  for(int i=1; i<=P; i++)
    cout << area[i] << " ";
}
