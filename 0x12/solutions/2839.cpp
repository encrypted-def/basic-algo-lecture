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
