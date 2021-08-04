// Authored by : wogha95
// Co-authored by : -
// http://boj.kr/ea20c41a2ad946b8a5d2664d81804a97
#include <bits/stdc++.h>
using namespace std;

int result, input;

void play(int n){
  if(n == 0) cout << "D\n";  // 윷
  else if(n == 1) cout << "C\n";  // 걸
  else if(n == 2) cout << "B\n";  // 개
  else if(n == 3) cout << "A\n";  // 도
  else if(n == 4) cout << "E\n";  // 모
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  for(int r = 0; r < 3; r++) {
    result = 0;
    for(int c = 0; c < 4; c++) {
      cin >> input;
      result += input;
    }
    play(result);
  }
}