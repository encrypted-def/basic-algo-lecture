// Authored by : wogha95
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/5306be11066640fb96fa672ccd15b40c
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  int year;
  cin >> year;
    
  if(year % 4 == 0){
    // 4의 배수이면서 400의 배수
    if(year % 400 == 0)  cout << 1;
    // 4의 배수이면서 100의 배수
    else if(year % 100 == 0)  cout << 0;
    // 4의 배수이면서 100, 400의 배수가 아닌 수
    else  cout << 1;  
  }
  // 4의 배수가 아닌 수
  else  cout << 0;
}
