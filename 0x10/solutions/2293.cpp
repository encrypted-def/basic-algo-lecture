// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/84f97d22cd54454da34b0f0e51aeb94a
#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[10005], d[10005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  d[0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = a[i]; j <= k; j++)
      d[j] += d[j - a[i]];

  cout << d[k] << '\n';
}