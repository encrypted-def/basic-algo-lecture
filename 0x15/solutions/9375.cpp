// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/20eb099e71a94245b5ef25f23214130a
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
      clothings[b]++;
    }
    for (auto v : clothings) ans *= v.second + 1;
    cout << ans - 1 << '\n';  // 알몸인 경우를 제외합니다.
  }
}
