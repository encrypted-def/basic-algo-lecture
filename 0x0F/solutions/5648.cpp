// Authored by : std-freejia
// Co-authored by : -
// http://boj.kr/c56909c54c4f4e9fb2c987a6eb3b96ee
#include <bits/stdc++.h>
using namespace std;

int n;
string st;
vector<long long> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> st;
    reverse(st.begin(), st.end());
    v.push_back(stoll(st));
  }
  sort(v.begin(), v.end());
  for(auto i : v) cout << i << '\n';
  return 0;
}
