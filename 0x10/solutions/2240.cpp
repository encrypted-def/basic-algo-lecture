// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/8d19497b3eb04988bbacfff15129c98d
#include <bits/stdc++.h>
using namespace std;
int a[1002];
int d[1002][32][3]; // d[i][j][k]: i:현재시간, j:이동횟수, k:나무번호
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, w;
  cin >> t >> w;
  for (int i = 1; i <= t; i++)
    cin >> a[i];

  for (int i = 1; i <= t; i++) {
    // 이동하지 않는 경우 (2번 나무는 이동안하면 못감)
    d[i][0][1] = d[i - 1][0][1] + (a[i] == 1 ? 1 : 0);
    for (int j = 1; j <= w; j++) { // j번 이동
      if (i < j) break; // 현재 시간보다 많이 이동할 수 없다
      if (a[i] == 1) { // 1번 나무인 경우
        d[i][j][1] = max(d[i - 1][j - 1][2], d[i - 1][j][1]) + 1;
        d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]);
      }
      else { // 2번 나무인 경우
        d[i][j][1] = max(d[i - 1][j - 1][2], d[i - 1][j][1]);
        d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]) + 1;
      }
    }
  }
  int ans = 0;
  for (int j = 0; j <= w; j++)
    ans = max({ans, d[t][j][1], d[t][j][2]});
  cout << ans;
}