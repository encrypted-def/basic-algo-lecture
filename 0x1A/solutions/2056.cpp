// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/c67ca9dd2a1442d7affc8f67f894a736
#include <bits/stdc++.h>
using namespace std;

int n, ans;
int dur[10'002]; // work duration
int ind[10'002]; // indegree
vector<int> rel[10'002]; // related node
vector<int> tt[1'000'002]; // time table, work to start

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> dur[i];
    int m; cin >> m;
    if(!m) tt[dur[i]].push_back(i);
    while(m--) {
      int x; cin >> x;
      rel[x].push_back(i);
      ind[i]++;
    }
  }

  for(int t = 0; t <= 1'000'000; t++) {
    for(int finished : tt[t]) {
      ans = t;
      for(int r : rel[finished]) {
        ind[r]--;
        if(ind[r] != 0) continue;
        tt[t + dur[r]].push_back(r);
      }
    }
  }
  cout << ans;
}