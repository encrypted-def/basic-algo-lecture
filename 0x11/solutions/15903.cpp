// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/d31166a680a14a8ea0b63e5a3eb5f79a
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1001];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i=0; i<n; i++) cin >> a[i];
  while (m--) {
    sort(a, a+n);
    ll tmp = a[0] + a[1];
    a[0] = tmp;
    a[1] = tmp;
  }
  ll ans = 0;
  for (int i=0; i<n; i++) ans += a[i];
  cout << ans;
}