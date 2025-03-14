// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/50fe25ca96ad4e8d8484f3a336d06db9
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll solve(ll k) {
  return floor(2 * sqrt(k) - 1e-9);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;
  ll x, y;
  while (tc--) {
    cin >> x >> y;
    cout << solve(y - x) << '\n';
  }
}
/*
다음 공간이동으로 이동할 수 있는 최대 거리의 역
A033638		Quarter-squares plus 1
https://oeis.org/A033638
*/