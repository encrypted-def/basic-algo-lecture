// Authored by : Hot6Mania
// Co-authored by : -
// http://boj.kr/2b8c4fa5fed849008ff86212e8be86b3

#include <bits/stdc++.h>
using namespace std;

int n;
int a[2010], d[2010][2010];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  for (int i = 1; i <= n; ++i) {
    d[i][i] = 1;
    if (a[i - 1] == a[i]) d[i - 1][i] = 1;
  }

  for (int gap = 2; gap < n; ++gap) {
    for (int i = 1; i <= n - gap; ++i) {
      int s = i, e = i + gap;
      if (a[s] == a[e] && d[s + 1][e - 1]) d[s][e] = 1;
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int s, e;
    cin >> s >> e;
    cout << d[s][e] << '\n';
  }

  return 0;
}
