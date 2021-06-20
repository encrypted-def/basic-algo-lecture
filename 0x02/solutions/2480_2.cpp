// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/a66f45063a2a4f1bb9816a2080077fe3
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a+3);
  if(a[0] == a[2]) cout << 10000 + a[0]*1000; // 세 수가 동일
  else if(a[0] == a[1] || a[1] == a[2]) cout << 1000 + a[1]*100; // 두 수가 동일
  else cout << a[2]*100;
}
