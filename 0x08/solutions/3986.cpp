// Authored by : yongjunleeme
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/216c90b92a494e9ba701e13ca9b7d7aa
#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while (n--) {
    string a;
    cin >> a;
    stack<int> S;
    for (auto c : a) {
      if (!S.empty() && S.top() == c) S.pop();
      else S.push(c);
    }
    if (S.empty()) ans++;
  }
  cout << ans << "\n";
}
