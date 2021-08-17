// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : OceanShape
// http://boj.kr/95fabdf15bf3499d88bb197069629cf8
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int A, B, C;
  cin >> A >> B >> C;
  int t=A*B*C;
  int d[10] = {};
  // 계산 결과를 자릿수별로 확인하여 저장
  while (t>0) {
    d[t%10]++;
    t/=10;
  }
  for (int i=0; i<10; ++i) cout << d[i] << '\n';
}