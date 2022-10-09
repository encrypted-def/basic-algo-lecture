// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/dd570a33a8e14e778224bb499a015ca3
#include <bits/stdc++.h>
using namespace std;

int n, x, y, d, g;
int board[105][105];
int cnt = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  while(n--){
    cin >> x >> y >> d >> g;

    vector<int> v;
    v.push_back(d%4);
    board[y][x] = 1;

    while(g--){
      int vSize = v.size();
      // 세대가 증가할 때마다 기존 세대의 방향(숫자)을 뒤에서부터 1을 더한 방향(숫자)을 추가
      // 0: 0
      // 1: 0, 1
      // 2: 0, 1, 2, 1
      // 3: 0, 1, 2, 1, 2, 3, 2, 1
      for(int j = vSize-1; j >= 0; j--)
        v.push_back((v[j]+1)%4);
    }

    for(int i = 0; i < v.size(); i++){
      int dir = v[i];
      if(dir == 0) x++;
      else if(dir == 1) y--;
      else if(dir == 2) x--;
      else if(dir == 3) y++;
      board[y][x] = 1;
    }
  }

  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      if(!board[i][j]) continue;
      if(board[i+1][j] && board[i][j+1] && board[i+1][j+1]) cnt++;
    }
  }
  cout << cnt;
}
