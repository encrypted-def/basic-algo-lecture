// Authored by : std-freejia
// Co-authored by : -
// http://boj.kr/2606a61ca3804fbea9cdeb42f72632c4
#include <bits/stdc++.h>
using namespace std;

int n, a, b;
vector<pair<int, int>> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < n; i++) cout << v[i].first << ' ' << v[i].second << '\n';
  return 0;
}
