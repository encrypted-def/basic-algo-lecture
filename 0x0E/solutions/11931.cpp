// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/59807f1dc1524512a0840b4ebb8998c9
#include <bits/stdc++.h>
using namespace std;

const int MXN = 2'000'000, HALF = MXN / 2;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<bool> isnum(MXN + 2);
  int N, t;
  cin >> N;
  while (N--) {
    cin >> t;
    isnum[t + HALF] = true;
  }
  for (int i = MXN; 0 <= i; i--)
    if (isnum[i]) cout << i - HALF << '\n';
}