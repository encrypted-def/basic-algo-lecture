// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/98a57090ad0b472f86492f495a362127
#include <bits/stdc++.h>
using namespace std;

int a[1000000];
int ans[1000000];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  stack<int> S;
  for (int i = n - 1; i >= 0; i--) {
    while (!S.empty() && S.top() <= a[i]) S.pop();
    if (S.empty())
      ans[i] = -1;
    else
      ans[i] = S.top();
    S.push(a[i]);
  }
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}
