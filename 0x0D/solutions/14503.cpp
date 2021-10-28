// Authored by : OceanShape
// Co-authored by : -
// http://boj.kr/9e6f61018d47427db29d056865f86f39
#include <bits/stdc++.h>
using namespace std;

int N, M, r, c, d, board[51][51], ans;
int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

// 해당 위치 청소가 가능한지 알려주는 함수
bool canClean(int x, int y){
  if(board[x][y] == 0) return true;
  return false;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> r >> c >> d;
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < M; ++j)
      cin >> board[i][j];

  int chkCnt = 0; // 방향 탐지 횟수
  while(true){
    int preAns = ans;
    // 청소하지 않은 빈 칸일 경우 청소
    if(board[r][c]==0) ++ans;
    board[r][c] = -1;

    int chkD = (d+3)%4; // 왼쪽으로 회전
    // 왼쪽 칸의 청소&통행가
    if(canClean(r+dirX[chkD], c+dirY[chkD])){
      d = chkD; // 회전한 방향 대입
      // 해당 위치로 이동
      r+=dirX[chkD];
      c+=dirY[chkD];
      chkCnt = 0; // 탐지 횟수 초기화
    } else {
      // 전부 확인하지 못했을 경우
      if(chkCnt != 4){
        d = chkD;
        ++chkCnt;
      }
      // 네 방향을 전부 확인했을 경우
      else {
        int backD = (d+2)%4;
        // [뒤가 벽으로 막혀 있으면, 로봇 청소기 종료]
        if(board[r+dirX[backD]][c+dirY[backD]]==1){
          break;
        }
        // 막혀 있지 않을 경우, 후진
        else {
          r+=dirX[backD];
          c+=dirY[backD];
          chkCnt = 0;
        }
      }
    }
  }

  cout << ans;
}
