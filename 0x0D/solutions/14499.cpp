// Authored by : OceanShape
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/f4d1f744e8284036b39106a41f13ffe2
#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, K, command;
int board[21][21];  // 지도
int dice[7];        // 주사위
//  윗면이 2이고, 동쪽을 바라보는 방향이 6
//     [1]
//  [5][2][6]
//     [3]
//     [4]

int idx[5][4] = {
  {},        // dummy
  {2,6,4,5}, // 동쪽, 5->2, 2->6, 6->4, 4->5
  {2,5,4,6}, // 서쪽, 6->2, 2->5, 5->4, 4->6
  {3,2,1,4}, // 북쪽, 4->3, 3->2, 2->1, 1->4
  {2,3,4,1}, // 남쪽, 1->2, 2->3, 3->4, 4->1
};

// 명령어가 유효한지 검증하는 함수
bool isOk(int nx, int ny){
  if(nx<0||nx>=N||ny<0||ny>=M) return false;
  return true;
}

// 주사위를 굴리는 함수
void roll(int com){
  // 회전 시 기존 주사위의 값을 별도로 보존하기 위한 배열 생성
  int tmp[7];
  for(int i = 1; i <= 6; ++i) tmp[i]=dice[i];

  // 굴리는거 처리
  for(int i = 0; i < 4; i++)
    tmp[idx[com][i]] = dice[idx[com][(i+1)%4]];

  // 회전 결괏값을 기존 주사위에 대입
  for(int i = 1; i <= 6; ++i) dice[i]=tmp[i];
}

void score(int c){
  int nx=x, ny=y;
  // 주사위 위치 이동
  if(c==1) ++ny;
  else if(c==2) --ny;
  else if(c==3) --nx;
  else ++nx;

  if(isOk(nx, ny)){
    x=nx; y=ny; // 유효성 확인 후 주사위의 위치 대입
    roll(c);
    // 0일 경우
    if(board[nx][ny]==0)
      board[nx][ny]=dice[4]; // 칸에 바닥면 값 대입
    
    // 0이 아닐 경우
    else {
      dice[4]=board[nx][ny]; // 바닥면에 칸 값 대입
      board[nx][ny]=0; // 칸 값을 0으로 초기화
    }
    cout << dice[2] << '\n'; // 주사위 윗면 출력
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> x >> y >> K;
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < M; ++j)
      cin >> board[i][j];

  while(K--){
    cin >> command;
    score(command);
  }
}
