// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/4b93b3cef4514d12be63f71be03ec2ee
#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10005], d[10005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    fill(d, d + 10005, 0);
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    cin >> m;
    d[0] = 1;
    for (int i = 0; i < n; i++)
      for (int j = a[i]; j <= m; j++)
        d[j] += d[j - a[i]]; // j - a[i]에 a[i] 동전 추가
    cout << d[m] << '\n';
  }
}