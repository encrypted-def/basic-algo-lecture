// Authored by : jihwan0123
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/dfcfa653b8494b3082959f248edfb200
#include <bits/stdc++.h>
using namespace std;

string board[4];

// x : 번호, dir : 방향, 1번의 회전을 처리하는 함수
void go(int x, int dir) {
  int dirs[4] = {};
  dirs[x] = dir;
  // 왼쪽으로 회전을 전파
  int idx = x;
  while (idx > 0 && board[idx][6] != board[idx-1][2]){
    dirs[idx-1] = -dirs[idx];
    idx--;
  }
  
  // 오른쪽으로 회전을 전파
  idx = x;
  while (idx < 3 && board[idx][2] != board[idx+1][6]){
    dirs[idx+1] = -dirs[idx];
    idx++;
  }

  for(int i = 0; i < 4; i++) {
    if(dirs[i] == -1)
      rotate(board[i].begin(), board[i].begin()+1, board[i].end());    
    else if(dirs[i] == 1)
      rotate(board[i].begin(), board[i].begin()+7, board[i].end());
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for (int i = 0; i < 4; i++) cin >> board[i];
  int k;
  cin >> k;
  while (k--) {
    int x, dir;
    cin >> x >> dir;
    go(x - 1, dir);
  }
  int ans = 0;
  for (int i = 0; i < 4; i++)
    if (board[i][0] == '1') ans += (1 << i);
  cout << ans;
}

/*
STL에 rotate 함수가 있어서 회전을 다소 편하게 처리할 수 있다.
*/
