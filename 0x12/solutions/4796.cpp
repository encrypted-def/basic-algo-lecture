// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/d52d24386b4f4b1a9b3afe25dfc3eea2
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int i = 1;
  while (1) {
    int L, P, V;
    cin >> L >> P >> V;
    if (V == 0) break;
    cout << "Case " << i++ << ": " << V / P * L + min(V % P, L) << '\n';
  }
}
