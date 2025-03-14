// Authored by : jihwan0123
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/bf6d94e4ef624d2b864723a6933f0733
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
    swap(a[0], *min_element(a, a+n));
    swap(a[1], *min_element(a+1, a+n));   
    ll tmp = a[0] + a[1];
    a[0] = tmp;
    a[1] = tmp;
  }
  ll ans = 0;
  for (int i=0; i<n; i++) ans += a[i];
  cout << ans;
}
/*
매번 점수가 낮은 두 카드를 택하는 그리디로 통과 가능
*/
