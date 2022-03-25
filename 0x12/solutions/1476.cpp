// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/f10dafa7b28241d7a173b2be389804bf
#include <bits/stdc++.h>
using namespace std;

int e, s, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> e >> s >> m;
  e--, s--, m--;

  int i = e;
  for (; i % 28 != s; i += 15);

  int j = i;
  for (; j % 19 != m; j += lcm(15, 28));
  cout << j + 1;
}
