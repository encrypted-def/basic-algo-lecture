// Authored by : OceanShape
// Co-authored by : BaaaaaaaaaaarkingDog, kiiimiiin
// http://boj.kr/a7a4aa95c4ee446990f868f926993161
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N, a[10] = {}, ans = 0;
  cin >> N;
  
  // 자리수 추출
  while(N){
    a[N%10]++;
    N /= 10;
  }

  for(int i = 0; i < 10; i++){
    if(i == 6 || i == 9) continue;
    ans = max(ans, a[i]);
  }
  // (a[6]+a[9])/2를 올림한 값이 6, 9에 대한 필요한 세트의 수이므로 (a[6]+a[9]+1)/2을 계산
  ans = max(ans, (a[6]+a[9]+1)/2);
  cout << ans;
}
