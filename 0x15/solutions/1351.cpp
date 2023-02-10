// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/e81859b0268548ffad93a45b285dab49
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
int p, q;
unordered_map<ll, ll> um;

ll solve(ll x) {
  if(x == 0) return 1;
  if(um[x]) return um[x];

  um[x] = solve(x/p) + solve(x/q);
  return um[x];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> p >> q;
  cout << solve(n);
}
/*
해시를 활용한 DP 구현입니다.
재귀를 활용했으며,
값을 이미 계산했다면 그 값을 반환합니다.
*/