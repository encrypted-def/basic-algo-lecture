// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/78692d69bc014987b88c4b288ca1c95d
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

  int j = i, l = lcm(15, 28);
  for (; j % 19 != m; j += l);
  cout << j + 1;
}
