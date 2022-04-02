// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/6812e13888884382b73d53b4dcdbe11a
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, R;
  cin >> n >> R;
  
  while (--n) {
    int r;
    cin >> r;
    int g = gcd(R, r);  // C++17
    cout << R / g << '/' << r / g << '\n';
  }
}
/*
반지름이 R인 원을 1회 회전시키면 반지름이 r인 원은 R/r회 회전한다.
사이에 다른 원 r'이 있더라도 (R/r') * (r'/r)이 적용되어 소거된다.
*/
