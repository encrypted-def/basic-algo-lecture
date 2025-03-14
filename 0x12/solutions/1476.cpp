// Authored by : SciEm
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/802e3e33606e4782872c101b44c20e18
#include <bits/stdc++.h>
using namespace std;

int e, s, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> e >> s >> m;
  e--, s--, m--;

  int i = e;
  while(i % 28 != s) i += 15;

  int l = lcm(15, 28);
  while(i % 19 != m) i += l;
  cout << i + 1;
}
/*
C++17부터 numeric 헤더에 lcm 함수가 내장되어 있음 
*/
