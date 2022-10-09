// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/0143a4f9fd8b44be972815c0288286a5
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[105];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  d[1] = 1, d[2] = 1, d[3] = 1;

  for (int i = 4; i <= 100; i++)
    d[i] = d[i - 2] + d[i - 3];

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << d[n] << '\n';
  }
}