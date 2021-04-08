// Authored by : hgmhc
// Co-authored by : -
// http://boj.kr/0a6c583b11b74b169e7d471200c059bc
#include <iostream>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  pair<int,string> x[n];
  for (auto& s : x) cin >> s.first >> s.second;
  stable_sort(x, x+n, [&](pair<int,string> a, pair<int,string> b) {
    return a.first < b.first;
  });
  for (auto p : x) cout << p.first << ' ' << p.second << '\n';
}
