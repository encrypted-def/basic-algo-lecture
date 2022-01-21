// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/c941ea23822349c181e4c957389e836a
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int sm, sd, em, ed;
    cin >> sm >> sd >> em >> ed;
    v.push_back({sm * 100 + sd, em * 100 + ed});
  }
  sort(v.begin(), v.end());

  pair<int, int> cur;
  // 시작점 찾기
  int idx = 0, max_e = 301;
  for (int i = 0; i < n; i++){
    if (v[i].X > 301) break;
    if (v[i].Y > max_e) {
      idx = i;
      max_e = v[i].Y;
      cur = v[i];
    }
  }

  int ans = 1;
  while (cur.Y < 1201 && idx < n) {
    int max_idx = idx, max_val = cur.Y;
    for (int i = idx + 1; i < n; i++) // 다음 가능한 최대 범위 체크
      if (cur.Y >= v[i].X && max_val <= v[i].Y) {
        max_idx = i;
        max_val = v[i].Y;
      }
    if (idx == max_idx) break; // 이미 최대 범위면 종료
    idx = max_idx;
    cur = v[idx];
    ans++;
  }

  cout << (cur.Y >= 1201 ? ans : 0);
}