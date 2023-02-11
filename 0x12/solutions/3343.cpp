// Authored by : HJPark
// Co-authored by : -
// http://boj.kr/0d6a75ae9ed14455830186bc75293920
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, a, b, c, d;
ll ans = LLONG_MAX;

ll gcd(ll a, ll b) {
  while (b != 0) {
    ll r = a % b;
    a = b;
    b = r;
  }
  return a;
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> a >> b >> c >> d;

  if (a * d > b * c) {
    swap(a, c);
    swap(b, d);
  }

  ll lst = lcm(a, c);

  for (ll i = 0; i < (lst / a); i++) {
    ll cost = i * b;
    if (n - i * a > 0) cost += (((n - i * a - 1) / c) + 1) * d;
    ans = min(ans, cost);
  }

  cout << ans;
}

/*
1 송이당 가격이 더 비싼 것을 a, b로 만든다.
a와 c의 최소공배수 lst를 구한다.
a 장미는 lst/a 보다 적게 사야한다.
a 장미를 lst/a 이상 사는 경우는 c 장미를 통해서 더 싸게 구매할 수 있기 때문이다.
a = 0, 1,...,lst/a - 1 일 때 총 비용을 구한다.
a 장미를 i개 구매한 뒤 부족한 장미 (n-i*a)개는 c 장미를 통해서 채운다.
*/
