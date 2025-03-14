// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/b7b68ebcfcaa4a368313222b2b070559
#include <bits/stdc++.h>
using namespace std;
int a[100005][3], d[100005][3];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k = 1;
  while (1) {
    int n;
    cin >> n;
    if (n == 0) break;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 3; j++)
        cin >> a[i][j];

    d[0][0] = 1001;
    d[0][1] = a[0][1];
    d[0][2] = a[0][1] + a[0][2];

    for (int i = 1; i < n; i++) {
      d[i][0] = a[i][0] + min(d[i - 1][0], d[i - 1][1]);
      d[i][1] = a[i][1] + min({d[i - 1][0], d[i - 1][1], d[i - 1][2], d[i][0]});
      d[i][2] = a[i][2] + min({d[i - 1][1], d[i - 1][2], d[i][1]});
    }
    cout << k++ << ". " << d[n - 1][1] << '\n';
  }
}