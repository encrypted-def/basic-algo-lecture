// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/98c1742e07124ec0a3731f5e891a7651
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  set<int> hu;  // 홍익대학교의 명소들 위치
  int N, Q, t, curr = 1;
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) {
    cin >> t;
    if (t) hu.insert(i);
  }
  while (Q--) {
    cin >> t;
    switch (t) {
      case 1:
        cin >> t;
        if (hu.find(t) != hu.end())
          hu.erase(t);
        else
          hu.insert(t);
        break;
      case 2:
        cin >> t;
        curr = (curr + t - 1) % N + 1;
        break;
      case 3:
        if (hu.empty()) cout << -1 << '\n';
        else {
          auto it = hu.lower_bound(curr);
          if (it != hu.end())
            cout << *it - curr << '\n';
          else
            cout << N - curr + *hu.begin() << '\n';
        }
    }
  }
}