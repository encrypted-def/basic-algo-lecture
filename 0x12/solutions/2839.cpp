// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/3649d2bc821d41be958cb51fc82946d3
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  while (n >= 0) {
    if (n % 5 == 0) {
      ans += n / 5;
      cout << ans;
      return 0;
    }
    n -= 3;
    ans++;
  }
  cout << -1;
}

/*
3킬로그램 5개는 5킬로그램 3개로 치환이 되기 때문에 3킬로그램은 4개 이하로 사용하면 된다.
n이 5의 배수가 될 때 까지 3으로 빼주면 되는데, 이 때 n이 음수가 된다면
정확하게 n킬로그램을 만들 수 없는 상황이다.
*/
