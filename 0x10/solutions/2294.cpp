// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/a4f1202ad58a4973badecdf41c75c186
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
  fill(d, d + 10005, 100005);
  d[0] = 0; // 0원: 0개
  for (int i = 0; i < n; i++) {
    for (int j = a[i]; j <= k; j++)
      // 동전 하나 추가한 값과 기존 값 중 작은값
      d[j] = min(d[j], d[j - a[i]] + 1);
  }

  cout << (d[k] == 100005 ? -1 : d[k]) << '\n';
}