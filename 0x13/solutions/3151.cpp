// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/b830d64c3ecd434ba3e554cc709dba3e
#include <bits/stdc++.h>
using namespace std;

int n;
int a[10002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);

  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      auto ub = upper_bound(a + j + 1, a + n, -a[i] - a[j]);
      auto lb = lower_bound(a + j + 1, a + n, -a[i] - a[j]);
      ans += ub - lb;
    }
  }
  cout << ans;
}
/*
두 명을 선택하고 나머지 한 명을 이분탐색으로 찾되 여러 개 있는 경우를
고려하여 upper_bound와 lower_bound를 이용한다.
*/
