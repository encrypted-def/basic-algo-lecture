// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/11eb08243f224bfeb34e75ba14b42229
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
  if(a == 0) return b;
  return gcd(b % a, a);
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while(n--){
    ll a, b;
    cin >> a >> b;
    cout << lcm(a, b) << '\n';
  }
}