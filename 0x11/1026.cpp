// http://boj.kr/70c1305581914397aec5ce799ab69efb
#include <bits/stdc++.h>
using namespace std;

int a[105], b[105];
int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + n);
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += a[i] * b[n-1-i];
  cout << ans;
}
