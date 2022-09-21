// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/be09c4f3826d424882fc236985a18e24
#include <bits/stdc++.h>
using namespace std;

int p[1002];
vector< tuple<int, int, int> > e;

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool areindiffgr(int u, int v) {
  u = find(u), v = find(v);
  if(u == v) return 0;
  if(p[u] == p[v]) p[u]--;
  if(p[u] < p[v]) p[v] = u;
  else p[u] = v;
  return 1;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  fill(p, p + n, -1);

  int c;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      cin >> c;
      if(i == j) continue;
      e.push_back({c, i, j});
    }

  sort(e.begin(), e.end());
  
  int u, v;
  int cnt = 0;
  long long ans = 0;
  auto it = e.begin();
  while(cnt < n - 1) {
    tie(c, u, v) = (*it);
    it++;
    if(!areindiffgr(u, v)) continue;
    cnt++;
    ans += c;
  }
  cout << ans;
}