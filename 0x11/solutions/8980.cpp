// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/123db07eeef44a39b14ceb22d7f77f2b
#include <bits/stdc++.h>
using namespace std;

int N, C, M, ans;
int truck[2002];
vector<tuple<int, int, int>> orders;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> C >> M;
  int f, t, b;
  for (int i = 0; i < M; i++) {
    cin >> f >> t >> b;
    orders.push_back({t, f, b});
  }
  sort(orders.begin(), orders.end());
  for (auto v : orders) {
    tie(t, f, b) = v;
    bool loadable = true;
    for (int i = f; i < t; i++) {
      b = min(b, C - truck[i]);
      if (!b) {
        loadable = false;
        break;
      }
    }
    if (loadable) {
      ans += b;
      for (int i = f; i < t; i++) truck[i] += b;
    }
  }
  cout << ans;
}