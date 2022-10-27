// Authored by : ZeroOnePro
// Co-authored by : -
// http://boj.kr/506ddaad4af840d7863d1673880028ac
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, ans = 0;
  cin >> n;
  vector<int> a(n);
  vector<bool> is_used(n);
  int cnt = 0;
  for (auto& pt : a) {
    cin >> pt;
    cnt += pt;
  }
  if (cnt == 0) {
    cout << n;
    return 0;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n - 1; ++i) 
    for (int j = i + 1; j < n; ++j) {
      int target = a[i] + a[j];
      int ub = upper_bound(a.begin(), a.end(), target) - a.begin();
      int lb = lower_bound(a.begin(), a.end(), target) - a.begin();
      for (int cur = lb; cur < ub; ++cur)
        if (!is_used[cur] && cur != i && cur != j) {
          ans += 1;
          is_used[cur] = true;
        }
    }
  cout << ans;
  return 0;
}