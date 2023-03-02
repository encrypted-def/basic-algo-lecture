// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/fb9199f19a6341e399033c85ba7968d6
#include <bits/stdc++.h>
using namespace std;

int n;
int a[100000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0x7fffffff;
  for (int i = 0; i < n; i++) {
    int idx = lower_bound(a, a + n, -a[i]) - a;
    for (int j = idx - 1; j <= idx + 1; j++) {
      if (j < 0 || j >= n) continue;
      if (i == j) continue;
      if (abs(a[i] + a[j]) < abs(ans)) ans = a[i] + a[j];
    }
  }
  cout << ans;
}
