// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/d1e716682fbe499881cd32ec1c235f7e
#include <bits/stdc++.h>
using namespace std;

int nums[12];
int ops[12];  // ops[0]은 항상 더하기
int n;
int mn = 0x7f7f7f7f, mx = -0x7f7f7f7f;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  for (int op = 0, idx = 1; op < 4; op++) {
    int x; cin >> x;
    while (x--)
      ops[idx++] = op;
  }

  do {
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (ops[i] == 0) res += nums[i];
      else if (ops[i] == 1) res -= nums[i];
      else if (ops[i] == 2) res *= nums[i];
      else res /= nums[i];
    }
    mx = max(mx, res);
    mn = min(mn, res);
  } while (next_permutation(ops + 1, ops + n));
  cout << mx << '\n' << mn;
}
