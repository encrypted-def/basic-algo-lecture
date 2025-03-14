// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/5715f646f10e48e2b367b294f99ad43a
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  int len = 1, exp = 1;
  while (k > 9LL * len * exp) {
    k -= 9LL * len * exp;
    exp *= 10;
    len++;
  }
  int target = exp + (k - 1) / len;
  if (target > n) cout << -1;
  else cout << to_string(target)[(k - 1) % len];
}
/*
숫자들을 길이가 같은 것으로 묶으면 9(1~9), 180(10~99), 2700(100~999)
과 같이 자리를 차지하므로 k에서 9 * i * 10^(i - 1)을 순차적으로 빼주고
k번째 숫자를 포함하는 수 target을 찾는다.
*/
