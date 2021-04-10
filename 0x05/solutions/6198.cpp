// Authored by : unluckyjung
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/a84f083cdee3436f9f46acdef175e55f

#include <bits/stdc++.h>
using namespace std;

#define ll long long

stack<int> s;
int n;
ll ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  ll h;
  while (n--) {
    cin >> h;
    while(!s.empty() && s.top() <= h)
      s.pop();
    ans += s.size();
    s.push(h);
  }
  cout << ans;
  return 0;
}
