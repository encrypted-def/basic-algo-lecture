// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/5a8c26a75fd7433da8b814fc477b0317
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, p, q;
map<ll, ll> a;

ll go(ll x){
  if(a[x] != 0)
    return a[x];
  if(x == 0)
    return a[x] = 1;
  return a[x] = go(x/p) + go(x/q);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> p >> q;
  cout << go(n);
}
