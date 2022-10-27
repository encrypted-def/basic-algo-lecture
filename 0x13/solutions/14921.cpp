// Authored by : ZeroOnePro
// Co-authored by : -
// http://boj.kr/ee1b88c6f5cb413598516f82c98d97ff

#include <bits/stdc++.h>

using namespace std;

int abs(int x) { return x < 0 ? -x : x; }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, mn = 1e9 * 2 + 5;
  cin >> n;
  vector<int> sol(n);
  for (auto& s : sol) cin >> s;
  for (int i = 0; i < n; ++i) {
    int idx = lower_bound(sol.begin(), sol.end(), -sol[i]) - sol.begin();
    for (int nxt : {idx-1, idx, idx + 1})
      if (nxt >= 0 && nxt < n && nxt != i && abs(sol[i] + sol[nxt]) < abs(mn))
        mn = sol[i] + sol[nxt];
  }
  cout << mn;
  return 0;
}

 /**
  * 특정 용액의 최적의 쌍은 idx - 1, idx, idx + 1 중 하나에 위치함
  * 일부 용액에서는 최적의 쌍을 이루는 용액이 idx-2나 idx+2에 위치할 수 있지만, AC를 받는데는 지장이 없음
  * 이를테면, -99 -2 -1 6 98의 경우
  * -1의 최적의 쌍은 -2인데, 중간 과정에서 -1의 최적의 쌍이 6이 됨
  * 하지만 -2의 최적의 쌍을 구할 때 -1과 쌍을 이루기 때문에 정답 후보에 포함될 수 있음
  */