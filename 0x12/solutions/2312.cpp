// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/3d9755bab87944759be21205bbadfafe
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 100'000;

vector<int> pr;
bool ispr[MX + 2];

void prset() {
  for(ll p = 2; p <= MX; p++) {
    if(!ispr[p]) continue;
    pr.push_back(p);
    for(ll i = p; i * p <= MX; i++)
      ispr[i * p] = 0;
  }
}

void solve() {
  int x; cin >> x;
  for(int p : pr) {
    if(x == 1) break;
    if(x % p != 0) continue;
    if(ispr[x]) {
      cout << x << ' ' << 1 << '\n';
      return;
    }
    int cnt = 0;
    while(x % p == 0) {
      x /= p;
      cnt++;
    }
    cout << p << ' ' << cnt << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(ispr + 2, ispr + MX + 2, 1);
  prset();
  
  int t; cin >> t;
  while(t--) solve();
}