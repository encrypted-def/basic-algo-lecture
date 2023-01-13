// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/e507624dfaa04cc59c6fabf061ccb5e3
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  for(int i = 2; i * i <= n; i++) {
    int cnt = 0;
    while(n % i == 0) {
      cnt++;
      n /= i;
    }
    if(cnt) cout << i << ' ' << cnt << '\n';
  }
  if(n != 1) cout << n << ' ' << 1 << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}