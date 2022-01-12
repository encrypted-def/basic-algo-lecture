// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/315381ca33a546b3b328747e31c36db9
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int i = 1;
  while (1) {
    int L, P, V;
    cin >> L >> P >> V;
    if (!(L + P + V)) break;
    cout << "Case " << i++ << ": " << V / P * L + min(V % P, L) << '\n';
  }
}