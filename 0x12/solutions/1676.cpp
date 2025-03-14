// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/357ccbb40d504081b55f2d3f98590af4
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  while (n) {
    ans += n / 5;
    n /= 5;
  }
  cout << ans;
}
/*
10을 곱해야 0이 추가되므로 10이 몇번 곱해지는지 세면 된다.
10은 2 x 5 로 소인수 분해가 되는데 2의 배수가 5의 배수보다 많기 때문에 5의 개수만 세면 된다.
*/