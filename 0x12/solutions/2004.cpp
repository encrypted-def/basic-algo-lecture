// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/11adde96fad94208aa79c918e89e3a9e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, two, five;
ll find(ll num, int p){
  ll rtn = 0, div = p;
  while (num / div) {
    rtn += (num / div);
    div *= p;
  }
  return rtn;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  two = find(n, 2) - find(m, 2) - find((n - m), 2);
  five = find(n, 5) - find(m, 5) - find((n - m), 5);
  cout << min(two, five);
}