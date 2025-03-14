// Authored by : sukam09
// Co-authored by : -
// http://boj.kr/c4cfea370b7d4b9780bfb567bd505829
#include <bits/stdc++.h>
using namespace std;

int n, a, b;
vector<int> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> a >> b;
  if (a > b) swap(a, b);
  for (int i = 1; i <= n; i++) v.push_back(i);
  int ans = 0;
  
  while (v.size() > 1) {
    ans++;
    vector<int> nxt;
    for (int i = 0; i + 1 < v.size(); i += 2) {
      int x = v[i], y = v[i + 1];
      if (x == a && y == b) {
        cout << ans;
        return 0;
      }
      if (y == a || y == b) nxt.push_back(y);
      else nxt.push_back(x);
    }
    if (v.size() % 2 == 1) nxt.push_back(v.back());
    v = nxt;
  }
}
/*
v와 nxt는 각각 ans와 (ans + 1)번째 라운드에서 참가자들의 번호를 담고 있는 벡터.
해당 라운드에서 홀수 번째 참가자를 x, 짝수 번째 참가자를 y라 할 때 y가 김지민 또는 임한수가 아니라면
x를 다음 라운드에 진출시키는 것을 원칙으로 시뮬레이션한다.
*/