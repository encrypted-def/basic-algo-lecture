// http://boj.kr/6a7f35306b1446b1b01b057263879295
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int note[42][42];
int r, c;
int paper[12][12];

// paper를 90도 회전하는 함수
void rotate(){
  int tmp[12][12];
  
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      tmp[i][j] = paper[i][j];
  
  for(int i = 0; i < c; i++)
    for(int j = 0; j < r; j++)
      paper[i][j] = tmp[r-1-j][i];

  swap(r, c);
}

// note의 (x,y)에 모눈종이의 (0,0)이 올라가게 스티커를 붙일 수 있는지 판단하는 함수. 가능할 경우 note를 갱신한 후 true를 반환.
bool pastable(int x, int y){
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(note[x+i][y+j] == 1 && paper[i][j] == 1)
        return false;
    }
  }
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(paper[i][j] == 1)
        note[x+i][y+j] = 1;
    }
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  while(k--){
    cin >> r >> c;
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
        cin >> paper[i][j];
    
    for(int rot = 0; rot < 4; rot++){
      bool is_paste = false; // 해당 스티커를 붙였는가?
      for(int x = 0; x <= n-r; x++){
        if(is_paste) break;
        for(int y = 0; y <= m-c; y++){
          if(pastable(x, y)){
            is_paste = true;
            break;
          }
        }
      }
      if(is_paste) break;
      rotate();
    }
  }
  int cnt = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cnt += note[i][j];
  cout << cnt << '\n';
}
