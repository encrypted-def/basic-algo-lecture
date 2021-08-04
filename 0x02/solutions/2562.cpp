// Authored by : wogha95
// Co-authored by : -
// http://boj.kr/e8b0bfc16a1e4c9fbe75c66e7ec6c341
#include <bits/stdc++.h>
using namespace std;

int n, maxvalue, maxindex;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  for(int i = 1; i < 10; i++){
    cin >> n;
    // 전역변수의 초기값은 0이므로 바로 비교 가능합니다.
    if(maxvalue < n){
      maxvalue = n;
      maxindex = i;
    }
  }
  cout << maxvalue << "\n" << maxindex;
}