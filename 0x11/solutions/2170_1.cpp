// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/cc096d5140c749619c31d88da3d866e6
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> lines;
  for (int i=0; i<n; i++){
    int x, y;
    cin >> x >> y;
    lines.push_back({x, y});
  }
  sort(lines.begin(), lines.end());
  int l, r;
  tie(l, r) = lines[0];
  int ans = 0;
  for (int i = 1; i<n; i++) {
    int a, b;
    tie(a, b) = lines[i];
    if (a <= r && b >= r) r = b; // 앞의 선과 겹치는 부분이 있으면 '+' 방향으로 확장
    else if (a > r) { // 없으면 현재 선의 길이를 더하고, 새로운 선으로 변경
      ans += r - l;
      l = a;
      r = b;
    }
  }
  cout << ans + r - l;
}
