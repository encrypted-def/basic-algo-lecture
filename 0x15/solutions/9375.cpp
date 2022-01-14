// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/aea1460306194c019788557b4185c9f6
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--) {
    unordered_map<string, int> clothings;
    int N, ans = 1;
    cin >> N;
    string a, b;
    while (N--) {
      cin >> a >> b;
      if (clothings.find(b) == clothings.end()) clothings[b] = 1;
      else
        clothings[b]++;
    }
    for (auto v : clothings) ans *= v.second + 1;
    cout << ans - 1 << '\n';  // 알몸인 경우를 제외합니다.
  }
}