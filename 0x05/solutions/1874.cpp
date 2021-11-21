// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/5926f973a19c4bf398c573658842e198
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> S;
  int cnt = 1;
  string ans;
  while (n--) {
    int t;
    cin >> t;
    while (cnt <= t) {
      S.push(cnt++);
      ans += "+\n";
    }
    if (S.top() == t) {
      S.pop();
      ans += "-\n";
    }
  }
  if (S.empty())
    cout << ans;
  else
    cout << "NO";
}
