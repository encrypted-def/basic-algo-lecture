// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/7ce6914b23944568839e20e7b168f05e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  while(n--) {
    int x;
    cin >> x;
    pq.push(x);
  }
  while(m--){
    ll a = pq.top(); pq.pop();
    ll b = pq.top(); pq.pop();
    pq.push(a+b);
    pq.push(a+b);
  }
  ll ans = 0;
  while (!pq.empty()){
    ans += pq.top();
    pq.pop();
  }
  cout << ans;
}